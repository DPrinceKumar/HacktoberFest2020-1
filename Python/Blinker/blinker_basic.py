from string_with_arrows import *
import string

# Constants		####################################################

DIGITS = '0123456789'
LETTERS = string.ascii_letters
LETTERS_DIGISTS = LETTERS + DIGITS

# Tokens		####################################################

TT_INT		 	= 'INT'
TT_FLOAT 		= 'FLOAT'
TT_PLUS 	 	= 'PLUS'
TT_MINUS 	 	= 'MINUS'
TT_MUL 		 	= 'MUL'
TT_DIV 		 	= 'DIV'
TT_EQ		 	= 'EQ'
TT_LPAREN 	 	= 'LPAREN'
TT_RPAREN	 	= 'RPAREN'
TT_IDENTIFIER 	= 'IDENTIFIER'
TT_KEYWORD		= 'KEYWORD'
TT_EOF 		 	= 'EOF'
TT_POW 		 	= 'POW'
KEYWORDS = [
	'vr'
]

class Token:
	def __init__(self, type_, value=None, pos_start=None, pos_end=None):
		self.type = type_
		self.value = value
		if pos_start:
			self.pos_start = pos_start.copy()
			self.pos_end = pos_start.copy()
			self.pos_end.advance()

		if pos_end:
			self.pos_end = pos_end

	def matches(self, type_, value):
		return self.type == type_ and self.value == value

	def __repr__(self):
		if self.value: return f'{self.type}:{self.value}'
		return f'{self.type}'


# Errors		####################################################

class Error:
	def __init__(self, pos_start, pos_end,  error_name, details):
		self.error_name = error_name
		self.details = details
		self.pos_start = pos_start
		self.pos_end = pos_end

	def as_string(self):
		result = f'{self.error_name}:{self.details}\n'
		result += f'File{self.pos_start.fn}, line{self.pos_start.ln +1}'
		result += '\n\n' + string_with_arrows(self.pos_start.ftxt, self.pos_start, self.pos_end)
		return result

class CharacterNotFound(Error):
	def __init__(self, pos_start, pos_end, details):
		super().__init__( pos_start, pos_end,'Illegal Character ', details)

class InvalidSyntaxError(Error):
	def __init__(self, pos_start, pos_end, details=''):
		super().__init__( pos_start, pos_end,'Invalid Systax ', details)

class RTError(Error):
	def __init__(self, pos_start, pos_end, details, context):
		super().__init__( pos_start, pos_end,'Runtime Error ', details)
		self.context = context

	def as_string(self):
		result = self.generate_traceback()
		result += f'{self.error_name}:{self.details}\n'
		result += '\n' + string_with_arrows(self.pos_start.ftxt, self.pos_start, self.pos_end)
		return result
	def generate_traceback(self):
		result = ''
		pos = self.pos_start
		ctx = self.context

		while ctx:
			result = f'File {pos.fn}, line {str(pos.ln+1)}, in {ctx.display_name}\n' + result
			pos = ctx.parent_entry_pos
			ctx = ctx.parent

		return 'Traceback (most recent call last):\n' + result



# Position 		####################################################

class Position:
	def __init__(self, idx, ln, col, fn, ftxt):
		self.idx = idx
		self.ln = ln
		self.col = col
		self.fn = fn
		self.ftxt = ftxt

	def advance(self, current_char=None):
		self.idx += 1
		self.col += 1

		if current_char == '\n':
			self.ln += 1
			self.col = 0
		
		return self

	def copy(self):
		return Position(self.idx, self.ln, self.col, self.fn, self.ftxt)




# Lexer			####################################################

class Lexer:
	def __init__(self, fn, text):
		self.fn = fn
		self.text = text
		self.pos = Position(-1, 0, -1, fn, text)
		self.current_char = None
		self.advance()

	def advance(self):
		self.pos.advance(self.current_char)
		self.current_char = self.text[self.pos.idx] if self.pos.idx < len(self.text) else None

	def create_tokens(self):
		tokens = []

		while self.current_char != None:
			if self.current_char in ' \t':
				self.advance()
			elif self.current_char in DIGITS:
				tokens.append(self.create_number())
			elif self.current_char in LETTERS:
				tokens.append(self.make_identifier())
			elif self.current_char == '+':
				tokens.append(Token(TT_PLUS, pos_start=self.pos))
				self.advance()
			elif self.current_char == '-':
				tokens.append(Token(TT_MINUS, pos_start=self.pos))
				self.advance()
			elif self.current_char == '*':
				tokens.append(Token(TT_MUL, pos_start=self.pos))
				self.advance()
			elif self.current_char == '/':
				tokens.append(Token(TT_DIV, pos_start=self.pos))
				self.advance()
			elif self.current_char == '(':
				tokens.append(Token(TT_LPAREN, pos_start=self.pos))
				self.advance()
			elif self.current_char == ')':
				tokens.append(Token(TT_RPAREN, pos_start=self.pos))
				self.advance()
			elif self.current_char == '=':
				tokens.append(Token(TT_EQ, pos_start=self.pos))
				self.advance()
			elif self.current_char == '^':
				tokens.append(Token(TT_POW, pos_start=self.pos))
				self.advance()
			else:
				pos_start = self.pos.copy()
				char = self.current_char
				self.advance()
				return [], CharacterNotFound(pos_start, self.pos, "'"+char+"'")

		tokens.append(Token(TT_EOF, pos_start=self.pos))
		return tokens, None

	def create_number(self):
		num_str = ''
		dot_count = 0 
		pos_start = self.pos.copy()

		while self.current_char != None and self.current_char in DIGITS + '.':
			if self.current_char == '.':
				if dot_count == 1: break
				dot_count += 1
				num_str += '.'
			else:
				num_str += self.current_char
			self.advance()


		if dot_count == 0:
			return Token(TT_INT, int(num_str), pos_start, self.pos)
		else:
			return Token(TT_FLOAT, float(num_str), pos_start, self.pos)

	
	def make_identifier(self):
		id_str = ''
		pos_start = self.pos.copy()
		while self.current_char != None and self.current_char in LETTERS_DIGISTS + '_':
			id_str += self.current_char
			self.advance()

		tok_type = TT_KEYWORD if id_str in KEYWORDS else TT_IDENTIFIER
		return Token(tok_type, id_str, pos_start, self.pos)




# Node 			####################################################

class NumberNode:
	def __init__(self, token):
		self.token = token
		self.pos_start = self.token.pos_start
		self.pos_end = self.token.pos_end

	def __repr__(self):
		return f'{self.token}'

class VarAccessNode:
	def __init__(self, var_name_tok):
		self.var_name_tok = var_name_tok

		self.pos_start = self.var_name_tok.pos_start
		self.pos_end = self.var_name_tok.pos_end

class VarAssignNode:
	def __init__(self, var_name_tok, value_node):
		self.var_name_tok = var_name_tok
		self.value_node = value_node

		self.pos_start = self.var_name_tok.pos_start
		self.pos_end = self.value_node.pos_end
	
class BinOpNode:
	def __init__(self, left_node, op_token, right_node):
		self.left_node = left_node
		self.op_token = op_token
		self.right_node = right_node

		self.pos_start = self.left_node.pos_start
		self.pos_end = self.right_node.pos_end

	def __repr__(self):
		return f'({self.left_node}, {self.op_token}, {self.right_node})'

class UnaryOpNode:
	def __init__(self, op_token, node):
		self.op_token = op_token
		self.node = node

		self.pos_start = self.op_token.pos_start
		self.pos_end = node.pos_end

	def __repr__(self):
		return f'({self.op_token}, {self.node})'




# Parser 		####################################################

class Parser:
	def __init__(self, tokens):
		self.tokens = tokens
		self.tok_idx = -1
		self.advance()

	def advance(self):
		self.tok_idx += 1
		if self.tok_idx < len(self.tokens):
			self.current_tok = self.tokens[self.tok_idx]
		return self.current_tok


	def parse(self):
		res = self.expression()
		if not res.error and self.current_tok.type != TT_EOF:
			return res.failure(InvalidSyntaxError(self.current_tok.pos_start, self.current_tok.pos_end, "Expected '+', '-', '*', '/', '^'"))
		return res


	def atom(self):
		res = ParserResult()
		tok = self.current_tok

		if tok.type in (TT_INT, TT_FLOAT):
			res.register_advancement()
			self.advance()
			return res.success(NumberNode(tok))

		elif tok.type == TT_IDENTIFIER:
			res.register_advancement()
			self.advance()
			return res.success(VarAccessNode(tok))
		

		elif tok.type == TT_LPAREN:
			res.register_advancement()
			self.advance()
			expr = res.register(self.expression())
			if res.error: return res
			if self.current_tok.type == TT_RPAREN:
				res.register_advancement()
				self.advance()
				return res.success(expr)
			else:
				return res.failure(InvalidSyntaxError(self.current_tok.pos_start, self.current_tok.pos_end, "Expected ')'"))

		return res.failure(InvalidSyntaxError(tok.pos_start, tok.pos_end, 
			"Expected int, float, identifier, '+', '-' or '('"))

	def power(self):
		return self.binary_operation(self.atom, (TT_POW, ), self.factor)

	def factor(self):
		res = ParserResult()
		tok = self.current_tok

		if tok.type in (TT_PLUS, TT_MINUS):
			res.register_advancement()
			self.advance()
			factor = res.register(self.factor())
			if res.error: return res
			return res.success(UnaryOpNode(tok, factor))

		return self.power()

	def term(self):
		return self.binary_operation(self.factor, (TT_MUL, TT_DIV))

	def expression(self):
		res = ParserResult()
		if self.current_tok.matches(TT_KEYWORD, 'vr'):
			res.register_advancement()
			self.advance()

			if self.current_tok.type != TT_IDENTIFIER:
				return res.failure(InvalidSyntaxError(
					self.current_tok.pos_start, self.current_tok.pos_end
					,"Expected Identifier" ))

			var_name = self.current_tok
			res.register_advancement()
			self.advance()

			if self.current_tok.type != TT_EQ:
				return res.failure(InvalidSyntaxError(
					self.current_tok.pos_start, self.current_tok.pos_end, 
					"Expected '='"
				))
			res.register_advancement()
			self.advance()
			expr = res.register(self.expression())

			if res.error: return res
			return res.success(VarAssignNode(var_name, expr))
					
		node =  res.register(self.binary_operation(self.term, (TT_PLUS, TT_MINUS)))
		if res.error: 
			return res.failure(InvalidSyntaxError(self.current_tok.pos_start, self.current_tok.pos_end,
			"Expected 'vr', int, float, identifier, '+', '-' or '('"))
		return res.success(node)



	def binary_operation(self, func_a, ops, func_b=None):
		if func_b == None:
			func_b = func_a
		res = ParserResult()

		left = res.register(func_a())
		if res.error: return res

		while self.current_tok.type in ops:
			op_tok = self.current_tok
			res.register_advancement()
			self.advance()
			right = res.register(func_b())
			if res.error: return res
			left = BinOpNode(left, op_tok, right)

		return res.success(left)
		



# Parser Result ####################################################

class ParserResult:
	def __init__(self):
		self.error = None
		self.node = None
		self.advance_count = 0

	def register_advancement(self):
		self.advance_count += 1

	def register(self, res):
		self.advance_count += res.advance_count
		if res.error: self.error = res.error
		return res.node

		
	def success(self, node):
		self.node = node
		return self
		
	def failure(self, error):
		if not self.error or self.advance_count == 0:
			self.error = error
		
		return self




# Runtime Result

class RTResult:
	def __init__(self):
		self.value = None
		self.error = None

	def register(self, res):
		if res.error: self.error = res.error
		return res.value

	def success(self, value):
		self.value = value
		return self
	
	def failure(self, error):
		self.error = error
		return self




# Values 		####################################################
class Number:
	def __init__(self, value):
		self.value = value
		self.set_pos()
		self.set_context()

	def set_pos(self, pos_start=None, pos_end=None):
		self.pos_start = pos_start
		self.pos_end = pos_end
		return self

	def set_context(self, context=None):
		self.context = context
		return self
	
	def add_to(self, other):
		if isinstance(other, Number):
			return Number(self.value + other.value).set_context(self.context), None

	def subtract_by(self, other):
		if isinstance(other, Number):
			return Number(self.value - other.value).set_context(self.context), None

	def multiply_by(self, other):
		if isinstance(other, Number):
			return Number(self.value * other.value).set_context(self.context), None

	def power(self, other):
		if isinstance(other, Number):
			return Number(self.value ** other.value).set_context(self.context), None

	def divide_by(self, other):
		if isinstance(other, Number):
			if other.value == 0:
				return None, RTError(other.pos_start, 
				other.pos_end, "Division by zero",
				self.context)
			return Number(self.value / other.value).set_context(self.context), None

	def copy(self):
		copy = Number(self.value)
		copy.set_pos(self.pos_start, self.pos_end)
		copy.set_context(self.context)
		return copy

	def __repr__(self):
		return f'{self.value}'




# Context 		####################################################
class Context:
	def __init__(self, display_name, parent=None, parent_entry_pos = None):
		self.display_name = display_name
		self.parent = parent
		self.parent_entry_pos = parent_entry_pos
		self.symbol_table = None




# Symbot Table  ####################################################
class SymbolTable:
	def __init__(self):
		self.symbols = {}
		self.parent = None

	def get(self, name):
		value = self.symbols.get(name, None)
		if value == None and self.parent:
			return self.parent.get(name)
		return value
	
	def set(self, name, value):
		self.symbols[name] = value

	def remove(self, name):
		del self.symbols[name]




# Interpreter 	####################################################

class Interpreter:
	def visit(self, node, context):
		method_name = f'visit_{type(node).__name__}'
		method = getattr(self, method_name, self.no_visit_method)
		return method(node, context)

	def no_visit_method(self, node, context):
		raise Exception(f'No visit_{type(node).__name__} method defined')
		
	def visit_NumberNode(self, node, context):
		return RTResult().success(Number(node.token.value).set_context(context).set_pos(node.pos_start, node.pos_end))

	def visit_VarAccessNode(self, node, context):
		res = RTResult()
		var_name = node.var_name_tok.value
		value = context.symbol_table.get(var_name)

		if not value:
			return res.failure(RTError(
				node.pos_start, node.pos_end, 
				f"'{var_name}' is not defined", context
			))
		value = value.copy().set_pos(node.pos_start, node.pos_end)
		return res.success(value)

	def visit_VarAssignNode(self, node, context):
		res = RTResult()
		var_name = node.var_name_tok.value
		value = res.register(self.visit(node.value_node, context))
		if res.error: return res

		context.symbol_table.set(var_name, value)
		return res.success(value)

	def visit_BinOpNode(self, node, context):
		res = RTResult()
		left = res.register(self.visit(node.left_node, context))
		if res.error: return res
		right = res.register(self.visit(node.right_node, context))
		if res.error: return res

		result = ""
		error = ""
		if node.op_token.type == TT_PLUS:
			result, error = left.add_to(right)
		elif node.op_token.type == TT_MINUS:
			result, error = left.subtract_by(right)
		elif node.op_token.type == TT_MUL:
			result, error = left.multiply_by(right)
		elif node.op_token.type == TT_DIV:
			result, error = left.divide_by(right)
		elif node.op_token.type == TT_POW:
			result, error = left.power(right)

		if error:
			return res.failure(error)
		else:
			return res.success(result.set_pos(node.pos_start, node.pos_end))
		

	def visit_UnaryOpNode(self, node, context):
		res = RTResult()
		number = res.register(self.visit(node.node, context))
		if res.error: return res

		error = None
		if node.op_token.type == TT_MINUS:
			number, error = number.multiply_by(Number(-1))

		if error:
			return res.failure(error)
		else:
			return res.success(number.set_pos(node.pos_start, node.pos_end))





# Run			####################################################

global_symbol_table = SymbolTable()
global_symbol_table.set("null", Number(0))

def run(fn, text):
	#Generate tokens
	lexer = Lexer(fn, text)
	tokens, error = lexer.create_tokens()
	if error: return None, error

	#Generate AST
	parser = Parser(tokens)
	ast = parser.parse()
	if ast.error: return None, ast.error

	#Run Interpreter
	interpreter = Interpreter()
	context = Context('<program>')
	context.symbol_table = global_symbol_table
	result = interpreter.visit(ast.node, context)

	return result.value, result.error

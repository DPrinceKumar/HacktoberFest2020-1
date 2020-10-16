def isBalanced(s):
    st = []

    for i, next in enumerate(s):
        if next in "([{":
            st.append(next)
            if(st!=[]):
                print(i)
        if next in ")]}":
            if st==[]  :return False
            if (next =='}' and st.pop()=='{') or (next ==']' and st.pop()=='[' ) or(next ==')' and st.pop()=='('):
                # print(i)
                if len(st)==0:
                    # print("SUCCESS")
                    return True
                else:
                    st.pop()
                    return False


            else:

                print(i)
    if st==[] :return False

ss =input()
result = isBalanced(ss)
print(result)

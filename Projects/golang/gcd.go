package main
import(
	"fmt"
)


func gcd(a, b int)(int){
	if a<b {
	   a, b = b, a
	}
	if a % b == 0{
		return b
	}else{
		num:= gcd(b, a%b)
		return num
		
	}
	return 0
}


func main(){
	var number1, number2 int
	fmt.Printf("Enter the first number")	
	fmt.Scanln(&number1)
	fmt.Printf("Enter the second number")
	fmt.Scanln(&number2)
	GCD:=gcd(number1, number2)
	fmt.Println("GCD of ",number1," and ",number2,"is",GCD)
}

// Infix to Postfix
#include<iostream>
#include<string>
using namespace std;

int top = -1;
int stack[10];

bool stackEmpty(){
	if(top==-1)
		return true;
	else
		return false;
}

bool stackFull(){
	if(top>=9)
		return true;
	else
		return false;
}

void push(char ele){
	if(stackFull())
		cout << "Stack Full. Cannot insert!" << endl;
	else
		stack[++top] = ele;
	
}

void pop(char &dataOut){
	if(stackEmpty())
		cout << "Stack empty. Cannot pop!" << endl;
	else{
		dataOut = stack[top--];
	}
		
}

int priority(char op){
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else
		return 0;
}


string inToPostFix(string formula){
	char postFixExpr[50];
	int count=0;
	for(int i=0; i<formula.length(); i++){
		if(formula[i] == '(')
			push(formula[i]);
		else if(formula[i] == ')'){
			char dataOut;
			pop(dataOut);
			while(formula[i] != '('){
				postFixExpr[count++] = formula[i];
				pop(dataOut);
			}
		}

		else if(formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '%'){
			char tokenOut;
			while(!stackEmpty() && priority(formula[i]) <= priority(stack[top])){
				pop(tokenOut);
				postFixExpr[count++] = tokenOut;
			}
			push(formula[i]);
		}

		else{
			postFixExpr[count++] = formula[i];
		}
	}

	while(!stackEmpty()){
		char dataOut;
		pop(dataOut);
		postFixExpr[count++] = dataOut;
	}

	string postFix = "";
	for(int i=0; i<count; i++){
		postFix+=postFixExpr[i];
	}

	return postFix;
	
		
}

int main(){
	string inputExpr;
	cout << "Enter infix expression: "; cin >> inputExpr;
	cout << "The corresponding postfix expression is: "<< inToPostFix(inputExpr) << endl;
}

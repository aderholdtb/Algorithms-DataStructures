#include<iostream>
#include"stack.h"
using namespace std;

bool checkOperator(char value);
void checkIfInt(int value);

int main(int argc, char *argv[]){//COMMAND LINE ARGUMENT = POSTFIX EXPRESSION
  string postfixCommand;//POSTFIX COMMAND GIVEN BY USER
  int currentIndex = 0; //CURRENT INDEX OF THE POSTFIX STRING

  char currentValue;   //CURRENT CHARACTER IN THE POSTFIX STRING
  int stackValue1;     //STACK VALUE A
  int stackValue2;     //STACK VALUE B
  int result;          //RESULT OF A OPERATOR B

  Stack stack;         //STACK OF THE POSTFIX COMMAND

  if(argc != 2){//CHECKS FOR COMMAND LINE ARGUMENTS
    cout<<"MISSING COMMAND LINE ARGUMENTS!!!"<<endl;
      exit(1);
  }

  postfixCommand = argv[1];

  cout<<"\n================="<<endl;
  cout<<"Brandon Aderholdt"<<endl;
  cout<<"Postfix Algorithm"<<endl;
  cout<<"June 10, 2015"<<endl;
  cout<<"=================\n"<<endl;

  for(int i = 0; i < postfixCommand.size(); i++){//WHILE THERE ARE CHARACTERS IN THE POSTFIX EXPRESSION
    currentValue = postfixCommand[currentIndex++];// TAKE A CHAR FROM THE STRING

    if(checkOperator(currentValue)){
      if(stack.size() < 2){//IF IT IS A VALUE POSTFIX EXPRESSION
	cout<<"ERROR: NOT ENOUGH VALUES TO COMPLETE EXPRESSION"<<endl;
	exit(1);
      }

      stackValue1 = stack.pop();//POP A AND B FROM THE STACK
      stackValue2 = stack.pop();

      if(currentValue == '+'){//IF ADD A AND B
	result = stackValue2 + stackValue1;
	cout<<"Adding "<<stackValue2<<" and "<<stackValue1<<endl;
      }
      else if(currentValue == '-'){//IF SUBTRACT A AND B
	result = stackValue2 - stackValue1;
	cout<<"Subtracting "<<stackValue2<<" and "<<stackValue1<<endl;
      }
      else if(currentValue == '*'){//IF MULTIPLY A AND B
	result = stackValue2 * stackValue1;
	cout<<"Multiplying "<<stackValue2<<" and "<<stackValue1<<endl;
      }
      else{//IF DIVIDE A AND B
	result = stackValue2 / stackValue1;
	cout<<"Dividing "<<stackValue2<<" and "<<stackValue1<<endl;
      }

      stack.push(result);//PUSH RESULT TO STACK
    }
    else{
      checkIfInt(currentValue - '0');//CHECK IF INT VALUE FOR ERROR CHECKING
      stack.push(currentValue - '0');//PUSH ONTO STACK IF NOT AN OPERATION
    }
  }

  if(stack.size() > 1)//IF THE STACK IS EMPTY
    cout<<"ERROR: TOO MANY VALUES IN STACK!!!"<<endl;
  else{
    result = stack.pop();
  }

  cout<<"\nThe Final answer is "<<result<<" for the postfix expression "<<postfixCommand<<"\n"<<endl; 
  return 0;
}

//RETURNS IF TRUE AN OPERATOR, TAKES CHARACTER OF THE POSTFIX EXPRESSION AS PARAMETER
bool checkOperator(char value){
  if(value == '*' || value == '/' || value == '-' || value == '+')
    return true;
  else
    return false;
}

//IF NOT AN OPERATOR, CHECK IF AN INTEGER
void checkIfInt(int value){
  if((value > 9) || (value < 1)){
    cout<<"INVALID COMMAND LINE ARGUMENTS!!!"<<endl;
    exit(1);
  }
}

#include<iostream>
#include<stack>
using namespace std;

class Stack
{
private:
	char A[101];
	int top;
public:
	void Push(int x);
	void Pop();
	int Top();
	bool IsEmpty();
};

void Reverse(char c[], int n){
	stack<char> s;
	for(int i=0; i<n; i++){
		s.push(c[i]);
	}
	for(int i=0; i<n; i++){
		c[i] = s.top();
		s.pop();
	}
}

int main(){
	char c[51];
	printf("Enter a string: ");
	gets(c);
	Reverse(c,strlen(c));
	printf("output = %s", c);
    char ch;
    cin >> ch;
    return 0;
}

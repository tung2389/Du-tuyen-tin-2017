
#include<iostream>
#include<string.h>
 
using namespace std;
 
 
void decryptMsg(string enMsg, int key){
    int msgLen = enMsg.size(), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];
 
    row = col = 0;
    k = -1;

    for(i = 0; i < msgLen; ++i){
        cout<<railMatrix[row][col++];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}
 
int main(){
	freopen("zigin.txt","r",stdin);
	freopen("zigout.txt","w",stdout);
    string enMsg;
    int key;
    char c;
    cin >> key;
  while(c!='#')
  {
  	cin >> c;
  	if(c!='#')
  	enMsg+=c;
  	}
    decryptMsg(enMsg, key);
    
    return 0;
}

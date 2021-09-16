/******************************************************************************
 * FILE: cifreX
 * DESCRIPTION:
 * Implements some encryptions algorithms like The Enigma Machine.
    (https://pt.wikipedia.org/wiki/Enigma_(máquina)
 * AUTHOR: Héricles Semedo (a21801188)
 * LAST REVISED: 2020/05
 ******************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void remove_space(char* input);
int text_is_valid(char* input,char* text, int init);
int text_is_valid(char* input,char* text,int init);
int n_is_number_2(char input1,char input2);
int n_is_number(char input);
int op_is_valid(char op);
void to_uppercase(char* text);
int get_n(char* input);
int get_text_init(int n);

void substitution_cipher(int n, char* text);
void substitution_cipher_reverse(int n, char* text);
void transposition_cipher_or_reverse(int n, char* text);

/*void extra_transposition_cipher();
void extra_transposition_cipher_reverse();
*/

int main(){
    //  +++++ boolean +++++:
    //int true = 1; 
    int false = 0;
    //  +++ +++ +++ +++ +++:

    char op = 0;
    int n = 0;
    int text_init = 0;
    char input[1000];
    char text[167];

    strcpy(input,"");
    strcpy(text,"");

    while(1){
        while(1){
            fgets(input,1024,stdin);
            remove_space(input);
            
            if(input[0] == 'q'){
                puts("Exiting->");
                return 0;
            }
            if(input[1] != ' ' || input[2] == ' '){
                //puts("Error: Unkown option");
                break;
            }

            op = input[0];

            if(op_is_valid(op) == false){
                break;
            }

            n = get_n(input);
            text_init = get_text_init(n);

            if(op == 's' || op == 'S'){
                if(n > 35 || n < -35){
                    puts("Error: out of bound");
                    break;
                }
            }
            else if(op == 't' || op == 'T'){
                if(n > 50 || n < 2){
                    puts("Error: out of bound");
                    break;
                }
            }

            if(text_is_valid(input,text,text_init) == false){
                break;
            }

            switch (op)
                {
                case 's':
                    to_uppercase(text);
                    substitution_cipher(n,text);
                    break;
                case 'S':
                    to_uppercase(text);
                    substitution_cipher_reverse(n,text);
                    break;
                case 't':
                    transposition_cipher_or_reverse(n,text);
                    break;
                case 'T':
                    transposition_cipher_or_reverse(n,text);
                    break;
                /*case 'e':
                    extra_transposition_cipher();
                    break;
                case 'E':
                    extra_transposition_cipher_reverse();
                    break;
                    */
            }
        }
    }
    return 0;
}
void remove_space(char* input){

    long unsigned int pos = 0;
    char new_input[1000];
    strcpy(new_input,"");
    
    while(pos < strlen(input)){
        if(input[pos]!=' '){
            break;
        }
        pos++;
    }

    long unsigned init = pos , end = strlen(input)-1;
    pos = 0;
    
    while(pos < end){
        new_input[pos] = input[init+pos];
        pos++; 
    }
    new_input[pos] = '\0';
    
    strcpy(input,new_input);
}
int n_is_number(char input){
    puts("entra 1");
    //  +++++ boolean +++++:
    int true = 1; 
    int false = 0;
    //  +++ +++ +++ +++ +++:
    
    if( input != '0' &&
        input != '1' &&
        input != '2' &&
        input != '3' &&
        input != '4' &&
        input != '5' &&
        input != '6' &&
        input != '7' &&
        input != '8' &&
        input != '9'
        ){
            return false;
        }
    return true;
}
int n_is_number_2(char input1,char input2){
    puts("entra 2");
    //  +++++ boolean +++++:
    int true = 1; 
    int false = 0;
    //  +++ +++ +++ +++ +++:
    
    if( input1 != '0' &&
        input1 != '1' &&
        input1 != '2' &&
        input1 != '3' &&
        input1 != '4' &&
        input1 != '5' &&
        input1 != '6' &&
        input1 != '7' &&
        input1 != '8' &&
        input1 != '9'
        ){
            return false;
        }
    if( input2 != '0' &&
        input2 != '1' &&
        input2 != '2' &&
        input2 != '3' &&
        input2 != '4' &&
        input2 != '5' &&
        input2 != '6' &&
        input2 != '7' &&
        input2 != '8' &&
        input2 != '9'){

            return false;
    }
    return true;
}
int text_is_valid(char* input,char* text,int init){
    //  +++++ boolean +++++:
    int true = 1; 
    int false = 0;
    //  +++ +++ +++ +++ +++:
    
    long unsigned int end = strlen(input)-1;
    long unsigned int pos = 0;
    char text1[500];
    
    while(pos < end){
        text1[pos] = input[init+pos];
        pos++; 
    }
    text1[pos] = '\0';

    if(strlen(text1) < 167){
      strcpy(text,text1);
      return true;
    }
    
    //puts("text muito grande!");
    return false;
}
int op_is_valid(char op){
    //  +++++ boolean +++++:
    int true = 1; 
    int false = 0;
    //  +++ +++ +++ +++ +++:

    if(op != 's' && 
	   op != 'S' && 
 	   op != 'e' && 
	   op != 'E' && 
	   op != 't' && 
	   op != 'q' && 
	   op != 'T'){
            puts("Error: Unkown option");
		    return false;
	   }
	return true;
}
void to_uppercase(char* text){
    long unsigned int pos = 0;
    while(pos < strlen(text)){
        if(islower(text[pos])){
            text[pos] = toupper(text[pos]);
        }
        pos++;
    }
} 
void substitution_cipher(int n, char* text){
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[50];
    strcpy(cipher,"");

	char s1[50];
    char s2[50];
    strcpy(s1,"");
    strcpy(s2,"");
    //char code[167];

    int init, pos, end;
    
    if(n < 0){
        pos = 0;
        init = 0;
        end = strlen(alphabet)+n;
        while(pos < end){
            s1[pos] = alphabet[init+pos];
            pos++; 
        }
        s1[pos] = '\0';
    
        pos = 0;
        init = strlen(alphabet)+n;;
        end = strlen(alphabet);
        while(pos < end){
            s2[pos] = alphabet[init+pos];
            pos++; 
        }
        s2[pos] = '\0';
    }
    else 
    {
        pos = 0;
        init = 0;
        end = n;
        while(pos < end){
            s1[pos] = alphabet[init+pos];
            pos++; 
        }
        s1[pos] = '\0';
        
        pos = 0;
        init = n;
        end = strlen(alphabet);
        while(pos < end){
            s2[pos] = alphabet[init+pos];
            pos++; 
        }
        s2[pos] = '\0';
    }

    strcpy(cipher,s2);
    strcat(cipher,s1);

    /*printf("\n");
    puts(alphabet);
    puts(cipher);
    puts(text);
    printf("\n");*/

	long unsigned int pos1 = 0, pos2 = 0;
    char code[strlen(text)];

    while(pos1 < strlen(text)){
        if(text[pos1]==' '){
            code[pos1]=' ';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='.'){
            code[pos1]='.';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='#'){
            code[pos1]='#';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==','){
            code[pos1]=',';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='"'){
            code[pos1]='"';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==';'){
            code[pos1]=';';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==':'){
            code[pos1]=':';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='-'){
            code[pos1]='-';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='_'){
            code[pos1]='_';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='!'){
            code[pos1]='!';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==39){
            code[pos1]=39;
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='$'){
            code[pos1]='$';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='%'){
            code[pos1]='%';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='&'){
            code[pos1]='&';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='/'){
            code[pos1]='/';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='('){
            code[pos1]='(';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==')'){
            code[pos1]=')';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='='){
            code[pos1]='=';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='?'){
            code[pos1]='?';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='>'){
            code[pos1]='>';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='<'){
            code[pos1]='<';
            pos1++;
            pos2=-1;
        } 
         else if(text[pos1]=='='){
            code[pos1]='=';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='+'){
            code[pos1]='+';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='/'){
            code[pos1]='/';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1] == alphabet[pos2]){
            code[pos1] = cipher[pos2];
            pos1++;
            pos2=-1;
        }
        pos2++;
    }
    code[pos1] = '\0';
	puts(code);
}
void substitution_cipher_reverse(int n, char* text){
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[50];
    strcpy(cipher,"");

	char s1[50];
    char s2[50];
    strcpy(s1,"");
    strcpy(s2,"");
    //char original[167];

    int init, pos, end;

    pos = 0;
    init = 0;
    end = n;
    while(pos < end){
        s1[pos] = alphabet[init+pos];
        pos++; 
    }
    s1[pos] = '\0';

    pos = 0;
    init = n;
    end = strlen(alphabet)-1;
    while(pos < end){
        s2[pos] = alphabet[init+pos];
        pos++; 
    }
    s2[pos] = '\0';

    strcpy(cipher,s2);
    strcat(cipher,s1);
    
	long unsigned int pos1 = 0, pos2 = 0;
    char original[strlen(text)];
    strcpy(original,"");

    while(pos1 < strlen(text)){
        if(text[pos1]=='.'){
            original[pos1]='.';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==' '){
            original[pos1]=' ';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='#'){
            original[pos1]='#';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==','){
            original[pos1]=',';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==';'){
            original[pos1]=';';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==':'){
            original[pos1]=':';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='-'){
            original[pos1]='-';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='_'){
            original[pos1]='_';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='!'){
            original[pos1]='!';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==39){
            original[pos1]=39;
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='$'){
            original[pos1]='$';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='%'){
            original[pos1]='%';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='"'){
            original[pos1]='"';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='&'){
            original[pos1]='&';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='/'){
            original[pos1]='/';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='('){
            original[pos1]='(';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]==')'){
            original[pos1]=')';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='='){
            original[pos1]='=';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='?'){
            original[pos1]='?';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='>'){
            original[pos1]='>';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='='){
            original[pos1]='=';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='+'){
            original[pos1]='+';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='/'){
            original[pos1]='/';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1]=='<'){
            original[pos1]='<';
            pos1++;
            pos2=-1;
        }
        else if(text[pos1] == cipher[pos2]){
            original[pos1] = alphabet[pos2];
            pos1++;
            pos2=-1;
        }
        pos2++;
    }
    original[pos1] = '\0';
    puts(original);
}
void transposition_cipher_or_reverse(int n, char* text){
    int n_linhas = 0;

    if(strlen(text)%n == 0){
        n_linhas = strlen(text)/n;
    }
    else
    {
        n_linhas = strlen(text)/n;
        n_linhas++;
    }

    char mat[n_linhas][n];

    int letra = 0;

    for(int j=0; j < n_linhas; j++){
        for(int i=0; i < n; ++i){
            mat[j][i] = ' ';
            letra++;
        }
    }
    letra = 0;

    for(int j=0; j < n_linhas; j++){
        for(int i = 0; i < n; ++i){
            if(text[letra] == '\0'){
            }
            else
            {
            mat[j][i] = text[letra];
            letra++;
            }
        }
    }
    letra = 0;
    
    char code[strlen(text)];
    strcpy(code,"");
    
    for(int j=0; j < n; j++){
        for(int i=0; i < n_linhas; ++i){
            code[letra] = mat[i][j];
            letra++;
        }
    }
    code[letra]='\0';
    puts(code);

}
int get_n(char* input){
    char n[7];
    strcpy(n,"");
    int init = 2;
    int pos = 0;

    while(input[init]!=' '){
        n[pos]=input[init];
        pos++; 
        init++;
    }
    n[pos]='\0';
    return atoi(n);  
}
int get_text_init(int n){
    if(n > 0 && n < 10){
        return 4;
    }
    if(n > 0 && n >= 10){
        return 5;
    }
    if(n < 0 && n <= -10){
        return 6;
    }
    return 5;
}
/*void extra_transposition_cipher(){
}
void extra_transposition_cipher_reverse(){
}*/
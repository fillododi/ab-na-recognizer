#include <stdio.h>

int main(){
    //automata initialization
    char alphabet[] = {'a', 'b'};
    enum states {q0, q1, q2, q3};
    int curr_state = q0;
    int final_states[] = {q2};

    //other variable declations
    int inAlphabet, i, isFinal;
    char* word;
    char curr_char;

    printf("Insert your input: ");
    do{
        //check if character is in alphabet
        scanf("%c", &curr_char);
        inAlphabet = 0;
        for(i = 0; i<sizeof(alphabet); i++){
            if(curr_char == alphabet[i]){
                inAlphabet = 1;
            }
        }
        if(inAlphabet || curr_char == '\n'){
            if(inAlphabet){
                //transition function
                switch(curr_state){
                    case q0:
                        if(curr_char == 'a'){
                            curr_state = q1;
                        } else {
                            curr_state = q3;
                        }
                    break;
                    case q1:
                        if(curr_char == 'a'){
                            curr_state = q2;
                        } else {
                            curr_state = q1;
                        }
                    break;
                    case q2:
                        curr_state = q3;
                    break;
                    case q3:
                        curr_state = q3;
                    break;
                }
            }
            
        } else {
            printf("Character not in alphabet.");
            break;
        }
    }
    while(curr_char != '\n');
    //check if ending state is final
    isFinal = 0;
    for(i = 0; i<(sizeof(final_states)/sizeof(int)); i++){
        if(curr_state == final_states[i]){
            isFinal = 1;
            break;
        }
    }
    //output
    if(isFinal){
        printf("String recognized!");
    } else {
        printf("String not recognized...");
    }

    return 0;
}
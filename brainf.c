#include <stdio.h>
#include "stack.h"

#define TAPE_SIZE 255

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: brainf-compiler <filename>\n");
        return 1;
    }
    FILE *file = fopen(argv[1] , "r");
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }
    char instruction, tape[TAPE_SIZE] = {0};
    int ip = 0;
    stack *loop_stack = NULL;
    while ((instruction = fgetc(file)) != EOF)
    {
        switch (instruction)
        {
        case '+':
            tape[ip]++;
            break;
        case '-':
            tape[ip]--;
            break;
        case '>':
            ip++;
            break;
        case '<':
            ip--;
            break;
        case '.':
            printf("%c", tape[ip]);
            break;
        case ',':
            scanf("%c", &tape[ip]);
            break;
        case '[':
            loop_stack = push(loop_stack, ftell(file));
            break;
        case ']':
            if(tape[ip]!=0){
                fseek(file, loop_stack->data, SEEK_SET);
            }
            else{
                loop_stack = pop(loop_stack);
            }
            break;
        default:

            break;
        }
    }
    return 0;
}

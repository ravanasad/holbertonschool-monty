#include "main.h"   

instruction_t opcodes[] = {
    {"push", f_push},
    {"pall", f_pall},
    {NULL, NULL}
};

instruction_t *find_func(char *opcode)
{
    int i = 0;
    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
            return (&opcodes[i]);
        i++;
    }
    return (NULL);
}
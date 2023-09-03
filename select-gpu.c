#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getCommand(char* command, char* option)
{    
    if(strcmp(option, "help") == 0)
    {
        strcpy(command, "system76-power help");
    }
    else
    {
        strcpy(command, "sudo system76-power graphics");
    }
}

int main()
{
    char command[256];
    getCommand(command, "help");
    printf("%s", command);
    printf("\nSystem may need reboot. Current gpu is:");
    system("sudo system76-power graphics");
    printf("\n\n");
    return 0;
}
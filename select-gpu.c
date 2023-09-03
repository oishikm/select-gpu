#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getCommand(char* command, char* option)
{    
    if(strcmp(option, "help") == 0)
    {
        strcpy(command, "system76-power help");
    }
    else if(strcmp(option, "default") == 0)
    {
        strcpy(command, "sudo system76-power graphics");
    }
    else
    {
        strcpy(command, "sudo system76-power graphics");
        strcat(command, " ");
        strcat(command, option);        
    }
}

int main()
{
    char command[256];
    char current_gpu[128];        
    getCommand(command, "help");
    printf("%s", command);
    FILE *fp = popen("sudo system76-power graphics", "r");
    fread(current_gpu, sizeof(char), 128, fp);
    printf("\nSystem may need to be rebooted. Current gpu is : %s\n", current_gpu);
    pclose(fp);
    return 0;
}

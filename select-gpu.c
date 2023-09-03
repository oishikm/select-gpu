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
        if(strcmp(option, "h") == 0) /* hybrid */
        {
            strcpy(option, "hybrid");
        }
        if(strcmp(option, "i") == 0) /* integrated */
        {
            strcpy(option, "integrated");
        }
        if(strcmp(option, "n") == 0 || strcmp(option, "d") == 0) /* nvidia - dedicated */
        {
            strcpy(option, "nvidia");
        }        
        if(strcmp(option, "c") == 0) /* compute */
        {
            strcpy(option, "compute");
        }
        sprintf(command, "sudo system76-power graphics %s", option);   
    }
}

int main(int argc, char** argv)
{
    char command[256];
    char current_gpu[128];
    char option[128];
    if(argc > 1)
    {
        strcpy(option, argv[1]);
    }
    else
    {
        strcpy(option, "default");
    }
    getCommand(command, "help");
    printf("%s", command);
    FILE *fp = popen("sudo system76-power graphics", "r");
    fread(current_gpu, sizeof(char), 128, fp);
    printf("\nSystem may need to be rebooted. Current gpu is : %s\n", current_gpu);
    pclose(fp);
    return 0;
}

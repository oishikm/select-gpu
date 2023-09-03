#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getCommand(char* command, char* option)
{    
    if  ( 
        strcmp(option, "help") == 0 ||
        strcmp(option, "-h") == 0 ||
        strcmp(option, "-help") == 0 ||
        strcmp(option, "--help") == 0
        )
    {
        printf  ( 
                    "\nselect-gpu\nWrapper for system76-power on Pop!_OS to select GPU."
                    "\nAvailable Options :\n-h, -help, --help, help"
                    "\t\t\tDisplays this information"
                    "\nd, n, nvidia"
                    "\t\t\t\tSwitch to dedicated NVIDIA GPU"
                    "\ni, integrated"
                    "\t\t\t\tSwitch to integrated GPU"
                    "\nh, hybrid"
                    "\t\t\t\tSwitch to hybrid GPU mode"
                    "\nc, compute"
                    "\t\t\t\tSwitch to compute mode for dedicated GPU"                                                            
                );
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
    char command[256] = "?\0";
    char current_gpu[128] = "?\0";
    char option[128] = "?\0";
    if(argc > 1)
    {
        strcpy(option, argv[1]);
    }
    else
    {
        strcpy(option, "default");
    }
    getCommand(command, option);
    system(command);
    FILE *fp = popen("sudo system76-power graphics", "r");
    fread(current_gpu, sizeof(char), 128, fp);
    printf("\nSystem may need to be rebooted. Current gpu is : %s\n", current_gpu);
    pclose(fp);
    return 0;
}

/*
 * select-gpu
 * Wrapper for system76-power on Pop!_OS to select GPU.
 * Reference: https://support.system76.com/articles/graphics-switch-pop/#from-the-command-line
 * 
 * Oishik M | 03 September 2023
 */

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
                    "\nselect-gpu"
                    "\n\nWrapper for system76-power on Pop!_OS to select GPU."                    
                    "\n\nUsage: select-gpu <OPTION>"
                    "\n\nAvailable Options:\n  -h, -help, --help, help"
                    "\tDisplays this information"
                    "\n  d, n, nvidia"
                    "\t\t\tSwitch to dedicated NVIDIA GPU"
                    "\n  i, integrated"
                    "\t\t\tSwitch to integrated GPU"
                    "\n  h, hybrid"
                    "\t\t\tSwitch to hybrid GPU mode"
                    "\n  c, compute"
                    "\t\t\tSwitch to compute mode for dedicated GPU"
                    "\n\nFor help on system76-power, run \"system76-power help\""                                                            
                );
        strcpy(command, " "); /* NOP */
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
    printf( "\nSystem may need to be rebooted if you just switched/changed GPU."
            "\nCurrent GPU is : %s\n", current_gpu);
    pclose(fp);
    return 0;
}

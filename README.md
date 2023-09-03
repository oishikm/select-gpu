# select-gpu
Wrapper for system76-power on Pop!_OS to select GPU.  
  
Reference: <a href="https://support.system76.com/articles/graphics-switch-pop/#from-the-command-line" target="_blank">Pop!_OS Graphics Switch</a>  
  
Tested on Pop!_OS 22.04 (Ubuntu 22.04 LTS) on Oracle VM VirtualBox.  
  
## Installation
- Clone this repository.
  ```
  git clone https://github.com/oishikm/select-gpu.git
  ```
- Move into the cloned repository.
  ```
  cd select-gpu
  ```
- Run the Makefile.
  ```
  make
  ```

## Usage

```select-gpu <OPTION>```  
  
(Above line is meant to be run if select-gpu is made available in PATH)  
If you are running select-gpu from within the repository folder, run the following instead:
  
```./select-gpu <OPTION>```  

### Available Options
  
| Option | Action |
|--------|--------|
|-h, -help, --help, help|Displays these options|
|d, n, nvidia|Switch to dedicated NVIDIA GPU|
|i, integrated|Switch to integrated GPU|
|h, hybrid|Switch to hybrid GPU mode|
|c, compute|Switch to compute mode for dedicated GPU|
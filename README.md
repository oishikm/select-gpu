# select-gpu
Wrapper for system76-power on Pop!_OS to select GPU.  
  
Reference: <a href="https://support.system76.com/articles/graphics-switch-pop/#from-the-command-line" target="_blank">Pop!_OS Graphics Switch</a>  
  
Tested on Pop!_OS 22.04 (Ubuntu 22.04 LTS) on Oracle VM VirtualBox.  
  
## Usage

```select-gpu <OPTION>```

### Available Options
  
| Option | Action |
|--------|--------|
|-h, -help, --help, help|Displays these options|
|d, n, nvidia|Switch to dedicated NVIDIA GPU|
|i, integrated|Switch to integrated GPU|
|h, hybrid|Switch to hybrid GPU mode|
|c, compute|Switch to compute mode for dedicated GPU|
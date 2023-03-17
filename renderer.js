const { ipcRenderer } = require('electron');
const selectFilesButton = document.querySelector('.select-files-button');

selectFilesButton.addEventListener('click', () => {
  ipcRenderer.send('open-file-dialog');
});

ipcRenderer.on('selected-file', (event, filePaths) => {
  console.log('Selected files:', filePaths);
  for (const filePath of filePaths) {
    ipcRenderer.send('compress-file', filePath);
  }
});

ipcRenderer.on('compress-file-success', (event, compressedFilePath) => {
  console.log('Compressed file:', compressedFilePath);
});

ipcRenderer.on('compress-file-error', (event, errorMessage) => {
  console.error('Error:', errorMessage);
});

const darkModeButton = document.querySelector('.dark-mode-btn');
const body = document.querySelector('body');

//Dark mode
darkModeButton.addEventListener('click', () => {
  body.classList.toggle('dark');
});
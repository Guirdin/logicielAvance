const pngquant = require("pngquant-bin");
const { app, BrowserWindow, ipcMain, dialog} = require('electron');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');

let mainWindow;

function createWindow() {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true,
      contextIsolation: false,
    },
  })
  ;

  mainWindow.loadFile('index.html');
  //Mettre le logiciel en grand écran dès le démarrage
  mainWindow.maximize();

  mainWindow.webContents.openDevTools();
}

app.whenReady().then(() => {
  createWindow();
  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow();
  });
});

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit();
});

ipcMain.on('open-file-dialog', (event) => {
  dialog.showOpenDialog({
    properties: ['openFile', 'multiSelections'],
    filters: [
      { name: 'Images PNG', extensions: ['png'] }
    ]
  }).then((result) => {
    if (!result.canceled && result.filePaths.length > 0) {
      event.sender.send('selected-file', result.filePaths);
    }
  }).catch((error) => {
    console.log(error);
  });
});


ipcMain.on('compress-file', (event, filePath) => {
  const tempPath = app.getPath('temp');
  const compressedFolderPath = path.join(tempPath, 'compressed-files');
  if (!fs.existsSync(compressedFolderPath)) {
    fs.mkdirSync(compressedFolderPath);
  }
  const fileName = path.basename(filePath);
  const compressedFilePath = path.join(compressedFolderPath, fileName);

  exec(`${pngquant} --force --output ${compressedFilePath} ${filePath}`, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      event.sender.send('compress-file-error', error.message);
      return;
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      event.sender.send('compress-file-error', stderr);
      return;
    }
    console.log(`stdout: ${stdout}`);
    event.sender.send('compress-file-success', compressedFilePath);
  });
  const { shell } = require('electron');

  // Ouvre le dossier compressed-files avec le gestionnaire de fichiers
  shell.openPath(compressedFolderPath);
  
});
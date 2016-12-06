# TinyHFS
Hierarchical file system implemented for the Orbit Booster Pack in conjunction with the TM4C123GXL. The system has a UNIX-like command line UI accessed through the Serial (UART) interface. 

## Hardware Components

* 32KB 24LC256 EEPROM integrated into the Orbit Booster Pack
* Serial (UART) interface

## Files

* Files can be of variable length
* Files are plain text
* Files are stored at the end of the EEPROM
* Every file contains a header (not visible to user) with the following attributes (in order as stored in the EEPROM):

   * File start address
   * File end address
   * Parent folder start address

* Each of the above attributes occupy 2 bytes (a short int) in the EEPROM
* The name of the file is restricted to 10 characters, but can be modified
* The total size of a file header is <i>[10 + (2 * 3)]</i> bytes = <b>16 bytes</b>

## Folders

* Folders are modeled as headers within the EEPROM
* Folders are found at the start of the EEPROM
* The Hierarchy is modeled as top-down and represented as follows: (E:/folder1/folder2/../file1.txt), where E:/ represents the root directory
* The root folder's address is 37767 - it is not represented in the EEPROM, as it is a hypothetical folder
* Every folder contains the following attributes (in order as stored in the EEPROM):

  * Folder name
  * Folder start address
  * Parent folder start address

* Each of the above attributes occupy 2 bytes (a short int) in the EEPROM
* The name of the folder is restricted to 10 characters, but can be modified
* The total size of a folder is <i>[10 + (2 * 2)]</i> = <b>14 bytes</b>

## Partitions

* The EEPROM is partitioned to separate the file headers, folders and files for efficiency and ease of access.
* 27,768 bytes are allocated to the file partition 
* 3,998 bytes are allocated to the file header partition
* 1,000 bytes are allocated to the folder partition
* This will allow us to store a maximum of 71 folders and 249 file headers in all cases
* If on average a file is composed of 300 bytes, the system can store 92 files
* The first byte of EEPROM is used to store the number of files in the system for utility
* The above byte is accessed as a state variable, and is referred to as the 'file count byte'
* The system will be represented in memory as follows:

 File Count Byte| ---- Folders ---- | --------------- Files --------------- | --------- File Headers ---------
 :-------------:| ----------------- | ------------------------------------- | -------------------------------- 
        0       | 1 --------- 1,000 | 1,001 ------------------------ 27,768 | 27,769 ------------------ 32,766 

## Commands

* The commands that have been implemented successfully to date are the following:

  * file [filename]    -> Creates new text file with the given file name - if file already exists, then throw an error
  * read [filename]    -> Displays the contents of the specified file
  * delfile [filename] -> Deletes the specified file
  * rnfile [filename]  -> Renames the specified file <br><br>
  * mkdir [foldername]  -> Creates new folder with the given folder name - if the folder already exists within the current directory, then throw an error
  * in [foldername]     -> Steps into the specified folder, down a level
  * out                 -> Steps up to the parent folder
  * delfol [foldername] -> Deletes the specified folder
  * rnfol [foldername]  -> Renames the specified folder <br><br>
  * ls     -> Prints the current folder's contents
  * pwd    -> Displays the current working directory
  * omem   -> Organizes the memory by removing gaps between adjacent files
  * help   -> Displays the list of commands
  * format -> Clears the entire file system

## UI

## Authors

Ben Upenieks and Chaitanya Varier

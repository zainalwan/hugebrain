<p align="center">
    <img src="https://raw.githubusercontent.com/zainalwan/hugebrain/master/assets/img/logo.png">
</p>

## Table of Contents
* [Table of Contents](#table-of-contents)
* [Introduction](#introduciton)
* [Installation](#installation)
* [Usage](#usage)

## Introduction
HugeBrain is a contact software. It used to store some data about the people
you know, including their name, phone, and email.

## Installation
This software require Boost library to work. To build and install this software,
do these following steps:
```
    $ cd src/
    $ make install
```
Then, executable will appear in as `../bin/hugebrain`.
In case you need some help about `make` commands, run this.
```
    $ make help
```
Note: work fine with Boost 1.75 and GCC 10.2.0 on Arch Linux x86_64.

## Usage
Assuming there is the executable `hugebrain` in your path. You could do this to
show help message.
```
    $ hugebrain --help
```
Without any argument given, the software will display the list of your contacts.
```
    $ hugebrain
```
### Adding Data(s)
You could add a data by run this command.
```
    $ hugebrain --add --name="Zain" --phone="+44 724 649 1123" 
    --email="zainalwan4@gmail.com"
```
![Adding data](assets/img/add.gif)

### Editing Data(s)
To edit an data, do this.
```
    $ hugebrain --edit --id=3 --name="John Doe" 
```
![Editing data](assets/img/edit.gif)

### Searching Data(s)
To search data, do this.
```
    $ hugebrain --search --name="parker"
```
![Searching data](assets/img/search.gif)

### Deleting Data(s)
To delete data, do this.
```
    $ hugebrain --delete --id=2
```
![Deleting data](assets/img/delete.gif)

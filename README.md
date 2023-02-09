# taurus-view

```
  ______                           _    ___             
 /_  __/___ ___  _________  ______| |  / (_)__ _      __
  / / / __ `/ / / / ___/ / / / ___/ | / / / _ \ | /| / /
 / / / /_/ / /_/ / /  / /_/ (__  )| |/ / /  __/ |/ |/ / 
/_/  \__,_/\__,_/_/   \__,_/____/ |___/_/\___/|__/|__/  
                                                        
```

TaurusView is a command line tool dealing with forex data. It allows for forex conversions at real-time rates and for viewing historical forex rates. Built for Ubuntu.

## Getting Started

You can easily install TaurusView on your Ubuntu system by using the provided script as explained in the following sections. You can also build it by using the provided script or manually. 

## Installation

* Clone the repository in a suitable location.

```shell
$ git clone git@github.com:kumuthu53/taurus-view.git
```

* Navigate into it.

```shell
$ cd taurus-view
```
* Run the install script with root user privileges. The install script will first run the build script and then install the resulting executable.

```shell
$ sudo bash install.sh
```
* Now you will be able to run TaurusView from anywhere using the terminal.
```shell
$ taurus-view
```

## Building

* If you do not want to install TaurusView you can just build it and run it from the executable.
* Clone the repository in a suitable location.

```shell
$ git clone git@github.com:kumuthu53/taurus-view.git
```

* Navigate into it.

```shell
$ cd taurus-view
```
* Run the build script. The build file will build the application. After installing the required library libcurl, it will use Cmake to generate the Makefile and then use make to build TaurusView. The resulting executable will be found in the directory 'build'. 

```shell
$ source build.sh
```
* Alternatively, you can open the project as a Cmake project in your favourite IDE and then build it. In this case, make sure to manually install libcurl with the following commands.
```shell
$ sudo apt-get update
$ sudo apt-get install libcurl4-openssl-dev
```
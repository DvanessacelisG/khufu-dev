# Khufu-Frontend
Hello and Welcome,
This is the repository for the frontend side of **Khufu**, the sourcing tool of Endava Bogotá.

### Tools
The project is built using
* ReasonReact (https://reasonml.github.io/reason-react/en/)
* bs-fluture (Fluture binding for Reason: https://github.com/benadamstyles/bs-fluture)

### Installation-Configuration- Development Environment
Why is it so important to consider a development environment when we work on a project?

* Type code and observe changes as soon as possible in our Docker containers (preferably without manual actions).

* Have a local environment that is representative of the actual deployment environment.

* This will make your life much easier in the long run and get new developers up and running on the project much more quickly.

**THE PREREQUISITES:** You need to install the following tools:

> Install VirtualBox. https://www.virtualbox.org/wiki/Downloads

* You can use VirtualBox to run entire operating systems within your own computer.

> Install Vagrant. https://www.vagrantup.com/downloads.html

* Vagrant is software that is used to manage a development environment. Through the command line, you can grab any available OS, install it, configure it, run it, work inside of it, shut it down, and more.

**CREATING/PROVIDING ENVIRONMENT** 

1) Create a folder in which you will work, if you have not already created it.

2) Inside of the folder clone the files to create/provision the environment

***(git clone -b vagrant https://github.com/DvanessacelisG/khufu-dev.git)***

Here you can find 2 files: 

> Vagrantfile: With the Vagrantfile we describe the type of machine required for a project, and how to configure and provision these machines.

> Provision: Provisioners in Vagrant allow you to automatically install software, alter configurations, and more on the machine as part of the vagrant up process.

3) Once you have the files in the folder, please changes in the Vagrantfile the next lines with your data:

```config.vm.synced_folder "C:/Users/dcelis/Desktop/khufu-D/khufu", "/home/vagrant/khufu"```

```C:/Users/dcelis/Desktop/khufu-D/khufu``` --> Path to the folder created in the first step.
4) In the current directory execute the following command 
```Vagrant up```

When this command will finish, you will have a virtual machine running khufu's project . You will not actually see anything though, since Vagrant runs the virtual machine without a UI. To prove that it is running, you can SSH into the machine:
```Vagrant ssh```

This command will drop you into a full-fledged SSH session. Go ahead and interact with the machine, if you want. 


https://fabianlee.org/2016/09/07/git-calling-git-clone-using-password-with-special-character/


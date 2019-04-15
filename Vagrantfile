# -- mode: ruby --
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
    config.vm.box = "ubuntu/xenial64"
    config.vm.network "forwarded_port", guest: 80, host: 80
    config.vm.network "forwarded_port", guest: 8001, host: 8001
    config.vm.provision "docker"
    config.vm.synced_folder "C:/Users/dcelis/Desktop/khufu-D/khufu", "/home/vagrant/khufu",
    mount_options: ["uid=0", "gid=0"] # to root user
    config.vm.provider :virtualbox do |vb|
      vb.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    end 
    config.vm.provision "shell" do |s|
      s.path = "provision.sh"
    end
  end
  
  

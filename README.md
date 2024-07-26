# Thrustmaster TMX Force Feedback racing wheel kernel module for the Linux kernel
Linux kernel module for the Thrustmaster TMX Force Feedback racing wheel. — The kernel module is not ready yet, you can't use the racing wheel with this kernel module for now. — Track the progress in GitHub issues or the TODOs part of the README.

**Note**: *I take no responsibility for any damages caused by the software. By that I mean devices ruined, devices bricked and more. Use this at your own risk.*

# Contributing
Any kind of contribution is appreciated, especially addressing issues in the GitHub issues tab.

Please use [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) commit "identifiers".

# TODOs
Here is the TODO list:

- [x] Initialize the kernel module (partially done)
- [ ] Report all buttons
- [ ] Report all axises
- [ ] Implement force feedback (* going to take a lot of time probably)
- [ ] Make a GUI for configuration

# Building
**! I HIGHLY ADVICE AGAINST RUNNING THIS KERNEL MODULE FOR NOW ! IT IS ONLY HERE FOR TESTING !**

You can build the kernel module with
```
$ make
```
in the `/src` directory then you can enable it with `insmod` and disable it with `rmmod`, you can check if it's active with `dmesg` or `lsmod`.

**! AGAIN, I HIGHLY ADVICE AGAINST RUNNING THIS KERNEL MODULE FOR NOW !**

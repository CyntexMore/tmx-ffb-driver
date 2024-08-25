# Thrustmaster TMX Force Feedback racing wheel kernel module for the Linux kernel
Linux kernel module for the Thrustmaster TMX Force Feedback racing wheel. — The kernel module is not ready yet, you can't use the racing wheel with this kernel module for now. — Track the progress in GitHub issues or the TODOs part of the README.

> [!NOTE]
> *This is not an official kernel module by Thrustmaster. I take no responsibility for any damages caused by the software. By that I mean devices ruined, devices bricked and more. Use this at your own risk.*

# Contributing
Any kind of contribution is appreciated, especially addressing issues in the GitHub issues tab.

Please use [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) commit "identifiers".

Always make pull requests for the [dev branch](https://github.com/CyntexMore/tmx-ffb-driver/tree/dev) instead of the main branch.

# TODOs

> [!IMPORTANT]
> Please don't forget that *tmx-ffb-driver* is still early in developement, don't expect it to work flawlessly, or even work at all.

Here is the TODO list:

- [x] Initialize the kernel module
- [x] Initialize the racing wheel (* partially done)
- [ ] Implement input handling
    - [ ] Report all buttons
    - [ ] Report all axes
- [ ] Implement force feedback (* going to take a lot of time probably)
- [ ] Implement configuration support
    - [ ] Implement support for loading configuration files
    - [ ] Allow user to specify maximum wheel rotation angle
    - [ ] Implement flexible autocenter configuration
    - [ ] Implement force feedback gain configuration
    - (* and more that I can't think of now)
- [ ] Make a GUI for configuration with QT

# Building
>[!CAUTION]
> I HIGHLY ADVISE AGAINST RUNNING THIS KERNEL MODULE FOR NOW! IT MIGHT BRICK THE LINUX KERNEL! IF IT DOES, TAKE A LOOK AT [THIS](https://github.com/CyntexMore/tmx-ffb-driver/issues/12) ISSUE.

To build the kernel module you can run
```
$ make
```
in the `/src` directory then you can run
```
$ insmod tmx_driver.ko
```
to activate it. You'll need root permissions to run `insmod` and you'll have to run `insmod` every time you want to activate the kernel module.

If you want to install it you can run
```
$ make install
```
in the `/src` directory and then you can modprobe it with
```
$ modprobe tmx_driver
```
You'll need root permissions to run `make install` (because it will mess with "root only" directories) and to modprobe it.

# Contributing

When contributing to this repository, please first check if similar issue is already created or not. While adding any algorithm check if it already exists in the repo. Create an [issue](https://github.com/dsc-iem/TheAlgorithms/issues) and discuss with the mentors about it to proceed ahead. Respect fellow contributors and maintainers and follow Code of Conduct.

If you don't have git on your machine, [install it](https://help.github.com/articles/set-up-git/).

## Fork this repository

Fork this repository by clicking on the fork button on the top of this page.
This will create a copy of this repository in your account.

## Clone the repository


Now clone the forked repository to your machine. Go to your GitHub account, open the forked repository, click on the code button and then click the _copy to clipboard_ icon.

Open a terminal and run the following git command:

```
git clone "url you just copied"
```

where "url you just copied" (without the quotation marks) is the url to this repository (your fork of this project). See the previous steps to obtain the url.


For example:

```
git clone https://github.com/Your_UserName/TheAlgorithms.git
```

## Create a branch

Change to the repository directory on your computer:

```
cd TheAlgorithms
```

Now create a branch using the `git checkout` command:

```
git checkout -b Branch-Name
```


## Make necessary changes and commit those changes

If you go to the project directory and execute the command `git status`, you'll see there are changes.

Add those changes to the branch you just created using the `git add` command:

```
git add .
```

Now commit those changes using the `git commit` command:

```
git commit -m "added .... algorithm in java"
```

## Push changes to GitHub

Push your changes using the command `git push`:

```
git push --set-upstream origin Branch-Name
```

## Submit your changes for review

If you go to your repository on GitHub, you'll see a `Compare & pull request` button. Click on that button.

Now submit the pull request.
 

Soon We'll be Review and merge your changes into the main branch of this project.

## Where to go from here?

Congrats! You just completed the standard _fork -> clone -> branch -> edit -> PR_ workflow that you'll encounter often as a contributor!


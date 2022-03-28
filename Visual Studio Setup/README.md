# Visual Studio Setup
 In this repo, we will be going over the steps to install **Visual Studio Professional 2022** and the Visual Studio **SonarLint** extension.

 ## Visual Studio Installation
 1. Navigate to this URL,

    https://visualstudio.microsoft.com/vs/

    and click on **Download Visual Studio**. In the corresponding dropdown, select **Professional 2022**.

    ![](./Images/visualStudio.png)

2. You should be prompted to install the Visual Studio Installer. Follow the setup for the installer.

3. In the installer, find where Visual Studio Professional 2022 is located, most likely in the Available tab,

    ![](./Images/installer.png)

    and click on the **install** button for Visual Studio Professional 2022. 
    
    When the options for what to install in addition with Visual Studio appear,
    click on **Desktop Development With C++**.

    ![](./Images/options.png)

4. With Visual Studio Professional 2022 Installed, launch it. You will be prompted to with several options. Choose to **Create a New Project**.

    ![](./Images/newProject.png)

    Afterwards, you'll be prompted for what type of program you would like to create. Choose to create a **Console App** program.

    ![](./Images/consoleApp.png)

5. Your project should then open up a "Hello World" program. 

    In the middle of the toolbar you will see two play buttons.

    ![](./Images/debugger.png) 
    
    The left one named "Local Windows Debugger" is your debugging tool. *We will go over this functionality in discussion*.

    The right one is your simple Run tool with no debugging.

    If you click the Run tool on the right, a console window will open and it should look as follows.

    ![](./Images/run.png)

6. If all runs without error, that means that your Visual Studio is set up correctly and is ready for C++ development. 

    Now we will install **SonarLint** which is a tool used to detect bugs early, help with code quality, and detect code smells. 

## SonarLint Installation
1. In the top toolbar of Visual Studio, go to Extensiosn -> Manage Extensions.

    ![](./Images/extensions.png)

2. The **Manage Extensions** window should pop up. In the top right, there is a search bar. In this search bar, type "sonarlint".

    The **Manage Extensions** window should look like this:

    ![](./Images/window.png)

3. Click **Download** next to the SonarLint for Visual Studio 2022 extension and you will install the plugin and be prompted to restart Visual Studio.

    When you close Visual Studio, this window will pop up:

    ![](./Images/vsix.png)

    Click **Modify** and follow the rest of the instructions.

4. Now you can reopen Visual Studio Professional 2022. The recent projects will now show and reopen the solution you just created. (The one I created is Testing.sln).

    ![](./Images/solution.png)

5. Next, we will need to configure the rules for sonar lint.

    In the top search bar in Visual Studio, search sonarlint like so:

    ![](./Images/search.png)

    Click on the option named "Analysis rule rules SonarLint".

6. A pop up window should open and there should be a button named "Edit rules settings".

    ![](./Images/editRules.png)

    Click on **Edit rules setings**.

7. A files named settings.json should open up and look like this:

    ![](./Images/settings.png)

    Copy and paste the contents of the **NewSettings.json** provided in this repo.

    **Note**: We will be updating this file throughout the quarter.

## Github Installation

You will also need to install Github. Follow these instructions to install Github


https://github.com/git-guides/install-git

I recommend installing Github Desktop if you're not familiar with github command-line.

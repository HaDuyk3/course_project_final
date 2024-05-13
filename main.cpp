#include <iostream>
#include "Course.h"
#include <string>
Course CS_256= Course ("1");
static int student_id_auto_increasement = 0;
void input_information()
{
    int num;
    std::string name = "";
    std::cout << "The number of groups in the class?";
    std::cin >> num;
    CS_256.setNumbeOfGroups(num);
    for (int i = 1; i <= num; i++)
    {
        CS_256.addNewGroup(i);
        int numstudent;
        std::cout << "How many students in group " << i <<"? ";
        std::cin >> numstudent;
        while (numstudent < 1) {
            std::cout << "Each group has at least one member. Please re-enter data: ";
            std::cin >> numstudent;
        }
        for (int j = 1; j <= numstudent; j++) 
        {
            std::cout << "Name of student " << j << " ";
            //id++
            student_id_auto_increasement++;
            std::cin >> name;
            CS_256.addNewStudent(student_id_auto_increasement, name);
            Student stu(student_id_auto_increasement, name);
            CS_256.addStudentToAGroup(&stu, i);
        }
    }
}
void display_information()
{
    char display;
    int groupnum;
    do
    {
        std::cout << "Do you want to display information for the whole class or by group (A/E(for the whole class/for each group)) ";
        std::cin >> display;
        if (display == 'A') {
            for (int i = 1; i <= CS_256.getNumberOfGroups(); i++) {
                std::cout << "group " << i << std::endl;
                CS_256.findGroupByID(i)->displayGroupInfor();
            }
        }
        if (display == 'E') {

            std::cout << "What group you want to display information? ";
            std::cin >> groupnum;
            CS_256.findGroupByID(groupnum)->displayGroupInfor();
        }
        std::cout << "Do you want to display information (Y/N)?";
        std::cin>> display;
    } while (display == 'Y');
}
void project_declaration()
{
    int numproject;
    std::cout << "How many projects for the course  ";
    std::cin >> numproject;
    CS_256.setNumberOfProjects(numproject);
    for (int i = 1; i <= CS_256.getNumberOfProjects(); i++) {
        std::cout << "Project " << i << "\n";
        int id,d,m,y;
        std::string description;
        std::cout << "ID:";
        std::cin >> id;
        std::cout << "description";
        std::cin >> description;
        std::cout << "Deadline:";
        std::cin >> d >> m >> y;
        Time deadline(d,m,y);
        std::cout << std::endl;
        CS_256.addNewProject(id, deadline);
        CS_256.findProjectbyID(id)->setDescription(description);
    }
}
void project_information()
{
    int projectid;
    std::cout << "What project you want to check?";
    std::cin >> projectid;
    std::cout <<"Description: " << CS_256.findProjectbyID(projectid)->getDescription() << '\n';
    std::cout <<"Deadline: "<< CS_256.findProjectbyID(projectid)->getDueDate().toString();
}
void submit_project()
{
    int gnum,pnum,sd,sm,sy;
    std::cout << "What group number?";
    std::cin >> gnum;
    std::cout << "What project number?";
    std::cin >> pnum;
    std::cout << "What submission date?";
    std::cin >> sd>>sm>>sy;
    Time submissiondate(sd,sm,sy);
    CS_256.submit(gnum, pnum, submissiondate);
}
void Displaysbyproject()
{
    int pid;
    std::cout << "Please enter project ID: ";
    std::cin >> pid;
    CS_256.statSubmissionByProjectID(pid);
}
void Displaysbygroup()
{
    int gid;
    std::cout << "Please enter group ID: ";
    std::cin >> gid;
    CS_256.statSubmissionByGroupID(gid);
}

void not_complete_or_submit()
{

}
int main() {
    int choice;

    do {
        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Group information\n";
        std::cout << "2. Project (assignment) deadline information\n";
        std::cout << "3. Submit project\n";
        std::cout << "4. Statistic\n";
        std::cout << "5. Overall Statistic\n";
        std::cout << "6. Find groups do not complete or submit on time\n";
        std::cout << "7. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            int choice_1 = 0;

            do {
                system("cls");
                std::cout << "Group information:\n";
                std::cout << "1.1 Input information\n";
                std::cout << "1.2 Display information\n";
                std::cout << "1.3 Save group information\n";
                std::cout << "1.4 Load group information\n";
                std::cout << "1.5 Quit\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice_1;

                switch (choice_1) {
                case 1: {
                    std::cout << "Input information\n";
                    input_information();
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Display information\n";
                    display_information();
                    system("pause");
                    break;
                }
                case 3: {
                    std::cout << "Save group information\n";
                    //tuan;
                    system("pause");
                    break;
                }
                case 4: {
                    std::cout << "Load group information\n";
                    //tuan;
                    system("pause");
                    break;
                }
                case 5:
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    system("pause");
                    break;
                }
            } while (choice_1 != 5);
            break;
        }
        case 2:
        {
            int choice_2 = 0;
            do {
               system("cls");
               std::cout << "Project (assignment) deadline information:\n";
               std::cout << "2.1 Project declaration\n";
               std::cout << "2.2 Project information\n";
               std::cout << "2.3 Quit\n";
               std::cin >> choice_2;
               switch (choice_2) {
               case 1: {
                   std::cout << "Project declaration\n";
                   project_declaration();
                   system("pause");
                   break;
               }
               case 2: {
                   std::cout << "Project information\n";
                   project_information();
                   system("pause");
                   break;
               }
               case 3:
                   break;
               }
            } while (choice_2 != 3);
            break;
        }
        case 3:
            std::cout << "Submit project\n";
            submit_project();
            system("pause");
            break;
        case 4:
            int choice_4 = 0;
            do{
            system("cls");
            std::cout << "Statistic\n";
            std::cout << "4.1 Displays a table show the state of submission of a project for groups\n";
            std::cout << "4.2 Displays a table show the state of submission of all projects  of a group.\n";
            std::cout << "4.3 Quit\n";
            std::cin >> choice_4;
            switch (choice_4) {
            case 1:{
                std::cout << "Displays a table show the state of submission of a project for groups.\n";
                Displaysbyproject();
                system("pause");
                break;
            }
            case 2: {
                std::cout << "Displays a table show the state of submission of all projects  of a group.\n";
                Displaysbygroup();
                system("pause");
                break;
            }
            case 3:break;
            }
            } while (choice_4 != 3);
            system("pause");
            break;
        case 5:
            std::cout << "Overall Statistic\n";
            //help
            system("pause");
            break;
        case 6:
            std::cout << "Find groups do not complete or submit on time\n";
            //not_complete_or_submit();
            system("pause");
            break;
        case 7:
            std::cout << "Quitting...\n";
            //help
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            system("pause");
            break;
        }

        std::cout << std::endl;
    } while (choice != 7);
    return 0;
}
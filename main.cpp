/*
    11-11-17
    Talal Jawaid
    Abby Lee
    CISP 430 - Data Structures and Algorithms
    Final Project
    A Knights Life
    Abby Functions 
        - winLose
        - cardStack
        - storyPrompt
    Talal Functions 
        - BST
        - BSTTRAVERSAL
        - play
         
*/

#include <cstddef>
#include <iostream>
#include <ctime>
#include<cstdlib>


using namespace std;


struct tree //binary tree
{
    tree *l, *r;
    int data;
}*root = NULL , *p=NULL;

struct stack // stack for Cards
{
  int data;
  stack *next;
}*top = NULL;

int stackSize=0;


int moveTracker[5]={-1,-1,-1,-1,-1}; //keeps track of which moves were made
                        //0 is left, 1 is right
int treeLevel=0; //keeps track of which level they're on

int coins =0;


int prompt() //prompts user for choice (1 or 2),returns 1 or 2(l/r)
{
    int choice=0;
    cout << "\nEnter your choice: ";
    cin >> choice;
    while(choice !=1 && choice !=2)
    {
            cout << "\nEnter your choice: ";
            cin >> choice;
    }
    return choice;
}

///ABBY CODE (CARD DECK)

void cardStack() // initializes cards in 52 slot stack
{
  int num;
  srand(time(NULL));
  for (int i = 0; i < 52 ; i++)
  {
    num = rand() % 10 + 1; // random # generator, numbers 1-10
    stack* newTop = new stack; // new node for stack
    newTop->data = num; // stores number in data of new node
    newTop->next = top;  // connects linked list
    top = newTop; // shifts pointer
    ++stackSize;
  }
}

//FIXED POPCARD
int popCard() //returns top card on stack
{

   stack* oldTop = top;
   top = top->next;
   int oldTopData = oldTop->data;
   oldTop->data = NULL; // sets old card to NULL - already used
   --stackSize;
   return oldTopData;
 }
//END FIXED POPCARD


 bool winLose(int num, int card) // parameters: story prompt choice and card number
{
  int result, numResult, cardResult;
  numResult = num%2; // finds remainder
  cardResult = card%2; // finds remainder

  if (numResult == cardResult)
  {
    cout << "\nWise  choice! You earned " << card*100 << " coins!";
    coins = coins + card*100;  // card is 1-10
    cout << "\nCoin total: " << coins <<endl;
    return 1; //ret true if they won, false if not
  }
  else
  {
    cout << "\nPoor choice... ";
    if ((coins!=0)&& (card*100 <= coins))
    {
      cout << "\nYou lost " << card*100 << " coins!";
      coins = coins - card*100;
    }
    cout << "\nCoin total: "<< coins<<endl;
    return 0;
  }

}

//STORY PROMPT FINAL
int storyPrompt(int num)// num is binary search tree value tree->data, returns whether user chose option 1 or 2
{
    switch(num)
    {
          case 1:
            cout << " It’s winter and you must join the army. The food runs out at camp and the spies have returned. The enemy is advancing. Do you… \n(1) Abscond \t (2) Fight for your life";
            return prompt();
            break;
          case 2:
            cout << "A plague sweeps through the land and the King asks you to help quarantine the sick, relocate the healthy, and bury the dead. Do you…\n(1)Decline and move out of town \t (2) Help the doctors";
            return prompt();
            break;
          case 3:
            cout << "You are tasked with guarding and transporting a mysterious chest across the kingdom. On the journey, one of your comrades decides to investigate the mysterious chest and break into it. He thinks there is treasure inside. Do you…\n(1) Tell him not to open the chest \t (2) Open the chest ";
            return prompt();
            break;
          case 4:
            cout << "An old potter begs you to find his son who has wandered into a nearby swamp and has become lost. Do you…\n (1) Decline and move on \t (2) Find the son";
            return prompt();
            break;
          case 5:
            cout << "You happen upon a town that is holding a horse race. The winner is promised food and a large coin purse. Your horse has been known to be quite the underdog racehorse in these situations, however, he doesn’t always listen to you. Do you… \n(1)Pay someone to race for you \t (2) Join the race yourself";
            return prompt();
            break;
          case 6:
            cout << "An old friend tells you of a great treasure hidden in the mountains. You set off to look for it but instead find a peasant family struggling to grow enough food for the winter. Do you…\n(1) Keep looking for the treasure \t (2) Stay and help the family with their crops ";
            return prompt();
            break;
          case 7:
            cout << "On your travels, you meet some peculiar merchants on the road side. They claim to be selling the best armor equipment in the kingdom. You decide to stop and check their wares and spot a gleaming sharp dagger in their equipment. They demand full price and you really want the knife. Do you… \n (1)Walk away \t (2) Try to barter";
            return prompt();
            break;
          case 8: // ROOT
             cout << "Welcome to A Knight's Life.\n Your goal is earn the most coins by choosing different plot twists. To choose A or B, Enter '1' for A and '2' for B. Have fun!! ";
            cout << "\n You arrive at your first tournament, a knight in red rides out into the tournament ring. You recognize him and realize he is the best knight in the land. Do you...\n (1) Surrender \t (2) Challenge Him to a Duel";
            return prompt();
            break;
          case 9:
            cout << "A terrible thunder storm catches you in the woods and you find yourself outside of an inn. A hooded figure springs out of the window and you hear someone yell “Thief!” from inside the inn. Do you… \n(1) Let the stranger pass \t (2) Tackle the thief and arrest him ";
            return prompt();
            break;
          case 10:
            cout << "A group of robbers attacks a nearby village and set about stealing all the livestock. You arrive at the scene and the robbers are already making their escape! Do you…\n(1) Stay to help the villagers \t (2) Set off to capture the robbers ";
            return prompt();
            break;
          case 11:
            cout << "The King asks you to deliver an important message to the important Wizard of the land. However, the road to the Wizard’s domain is a long and dangerous journey. Do you…\n(1) Decline the job offer \t (2) Take the job";
            return prompt();
            break;
          case 12:
           cout <<" As you journey through the land, you come across an abandoned gold mine. You decide to investigate and find yourself face-to-face with a old, fearsome dragon. Do you…\n(A) Run away immediately \t (2) Fight the Dragon";
            return prompt();
            break;
          case 13:
            cout << "The King decides to travel to the neighboring country to arrange peace agreements. You are assigned to be one of his body guards. One night, an assassin jumps onto King’s carriage. Do you… (1)Sound the alarm \t (2) Fight the assassin yourself";
            return prompt();
            break;
          case 14:
            cout << "The King has made you commander of his army. You decide your first action will be to surround the enemy’s city on both sides. There are rumors that the enemy’s army may have moved underground and are no longer in the city. Do you… \n(1) Pull back and reform your plans \t (2) Attack ";
            return prompt();
            break;
          case 15:
            cout << "You’ve lived an eventful career as a knight and one day, the Wizard tells you there may be a chance to win the hand of a beautiful princess in the mountains. When you arrive, the princess’s father poses a challenge you must complete in order to win his daughter’s hand. It will test your loyalty, bravery, and humility over the span of five years. Do you… \n(1) Leave \t (2) Accept the challenge ";
            return prompt();
            break;

          default:
            return 0;
            break;
    }
}
//STORY PROMPT FINAL


//ABBY CODE ENDS HERE


void BST (int inputVal) //inputs nodes into BST
{
    int value=inputVal;
    if (root == NULL)
            {
                root = new tree;
                root->data = value;
                root->r=NULL;
                root->l=NULL;
            }
            else
            {
                p = root;
                while(true)
                {
                    if (value < p->data)
                    {
                        if (p->l == NULL)
                        {
                            p->l = new tree;
                            p = p->l;
                            p->data = value;
                            p->l = NULL;
                            p->r = NULL;
                            break;
                        } // if left null
                        else if (p->l != NULL)
                        {
                            p = p->l;
                        } // if left != null
                    } // if value less than p

                    else if (value > p->data)
                    {
                        if (p->r == NULL)
                        {
                            p->r = new tree;
                            p = p->r;
                            p->data = value;
                            p->l = NULL;
                            p->r = NULL;
                  break;
               }// if r=NULL
                        else if (p->r != NULL)
                        {
                            p = p->r;
                        }// if != NULL
                     } // if grater than
                 }// while
            }// else
}
void BSTSET()
{
    //int i=1;
    //Level 0 starts here
    BST(8);
    //Level 1 starts here
    BST(4);
    BST(12);
    //Level 2 starts here
    BST(2);
    BST(6);
    BST(10);
    BST(14);
    //Level 3 starts here
    BST(1);
    BST(3);
    BST(5);
    BST(7);
    BST(9);
    BST(11);
    BST(13);
    BST(15);

}

void printLevel(struct tree* node , int level) //Use to test if tree is set up correctly, prints individual levels
{
   if(node == NULL)
   {
       //cout << "node at level: " << level << "was null" A;
       if(level==3)
            cout << "Failing at level 3"; //testing code
       return;
   }

   if( level == 0 )
   {
      cout << " " << node->data << " ";
      return ;
   }
   else
   {
      printLevel( node->l, level-1 ) ;

      printLevel( node->r, level-1 ) ;
   }
}
void printTree(struct tree* root) //Use to print entire tree
{
    int level=0;
    cout << "\n\n";
    cout << "Enter number of levels in tree: ";
    cin >> level;
    cout << "\n\t\t";
    for(int i=0;i<level;i++)
    {
        printLevel(root,i);
        cout << "\n\t\t";
    }
    return;

}
void printChildren(struct tree* node)
{

    cout << node->data << " ";
    return;
}
void printNodeChildren(struct tree* tree) //prints children of whichever node is passed
{
    cout << "Left: ";
    printChildren(tree->l);
    cout << "\nRight: ";
    printChildren(tree->r);
    return;
}
int valLeftChild(struct tree* node,int i) //returns value of left child, i at first call should be 0
{
    if(i==0)
        return valLeftChild(node->l,i+1); //calls left child, returns call which returned data in l.c
    return node->data; //returns data in left child

}
int valRightChild(struct tree* node,int i) //returns value of right child, i at first call should be 0
{
    if(i==0)
        return valRightChild(node->r,i+1); //calls right child, returns call which returned data in r.c
    return node->data; //returns data in right child

}





int bstTraversal(struct tree* node,int level) //traverses tree based on user Input
{
    bool choiceResult;
    //Need recursive solution that uses moveTracker array to navigate to whichever node we're on
    if(node == NULL )
        return -1; //if -1, went past last level
    if(moveTracker[level] == 0)
        bstTraversal(node->l,level+1); // pass left node if move was to left
    else if(moveTracker[level]==1)
        bstTraversal(node->r,level+1); //pass left node if move was to right
    cout << "\nYou are at node: " << node->data << endl;
    int choice = storyPrompt(node->data); //pass number of node to storyPrompt, choice results in left/right
    choiceResult = winLose(choice,popCard()); //storing result of whether they won or lost; win is 1,0 is loss
    choice--; //reducing choice to 0/1 for moveTracker


    if(choice==0) //if choice is left
    {
      moveTracker[level]=choice;      //setting level
      bstTraversal(node->l,level+1); //heading to next node
    }
    else if(choice ==1)
    {
      moveTracker[level]=choice;
      bstTraversal(node->r,level+1);
    }

}
void play()
{

    bool quit=0;//if user quits, it'll go to 1
    bool gameEnd=0;
    char playAgain;
    int numLevels = 4; //number of levels of story, change for larger trees/stories
    while(!quit)//if user chooses to quit, the game will completely end.
    {
        //initialize values here
        int score = 0; //Keeps track of user score
        while(!quit) //if game ends, user can choose to play again
        {
            quit=0;//if user quits, it'll go to 1
            gameEnd=0;
            playAgain= 'q';
            numLevels = 4; //number of levels of story, change for larger trees/stories
            stackSize=0;
            moveTracker[0]=-1; //keeps track of which moves were made
            moveTracker[1]=-1;
            moveTracker[2]=-1;
            moveTracker[3]=-1;
            moveTracker[4]=-1;
            treeLevel=0; //keeps track of which level they're on
            coins =0;
            bstTraversal(root,0);
            cout << "\n\nThank you for playing!";
            while((playAgain != 'y') && (playAgain != 'Y') && (playAgain !='n') && (playAgain != 'N'))
            {
                cout << "\n\nWould you like to play again? (y/n): ";
                cin >> playAgain;

            }
            if(playAgain=='y' || playAgain == 'Y')
                    quit=false;
            else if(playAgain=='n' || playAgain == 'N')
                    quit = true;
        }
    }
}
int main()
{
    cardStack(); //initialize card stack 
    BSTSET(); //calls BSTSET to initialize BST.

    play();

    cout << "\n\n\t\t";
        printLevel(root,0);
    cout << "\n\t      ";
    printLevel(root,1);
    cout << "\n\t   ";
    printLevel(root,2);
    cout << "\n\t";
    printLevel(root,3);
    cout << "\n\n";



}

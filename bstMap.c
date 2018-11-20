#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node
{
    char key[10];
    char value[10];
    struct Node *left,*right;
};

struct Node* createNode(char key[10], char value[10]){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->right=NULL;
    temp->left=NULL;
    strcpy(temp->key,key);
    strcpy(temp->value,value);
    return temp;
}

struct Node* map(struct Node* node,char key[10],char value[10]){
    if(node==NULL){
        return createNode(key,value);
    }
    else if(strcmp(node->key,key)<=0){
        node->left=map(node->left,key,value);
    }
    else if(strcmp(node->key,key)>0){
        node->right=map(node->right,key,value);
    }
    return node;
}

struct Node* valOf(struct Node* root,char key[10]){
    if(root==NULL){
        return(NULL);
    }
    if(strcmp(root->key,key)==0){
        return root;
    }
    else if(strcmp(root->key,key)<0){
        return valOf(root->left,key);
    }
    else if(strcmp(root->key,key)>0){
        return valOf(root->right,key);
    }
}

void display(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        display(root->left); 
        printf("%s \n", root->key); 
        display(root->right); 
    } 
} 

int main(){
    char key[10],value[10];
    int a;
    struct Node *root = NULL,*temp=NULL; 
    root = map(root, "root","sudo"); 
    map(root, "hello","hello_world"); 
    map(root, "time","precious");
    map(root,"username","password");
    map(root,"sasuke","uchiha");
    map(root,"Naruto","uzumaki");
    while(1){
        printf("Enter option\n1.Add key-Value\n2.Find Value of Key\n");
        scanf("%d",&a);
        switch(a){
            case 1: printf("Enter key-value\n");
                    scanf(" %s %s",key,value);
                    map(root,key,value);
                    printf("\n\nKeys\n\n");
                    display(root);
                    printf("\n\n");
                    break;
            case 2: printf("\n\n-----Keys-----\n");
                    display(root);
                    printf("\n\n");
                    printf("Enter key\n");
                    scanf(" %s",key);
                    temp = valOf(root, key);
                    if(temp == NULL){
                        printf("No such mapping \n");
                    }
                    else{
                        printf("\n\n\t\t\tThe value of %s ==> %s\n\n\n",key,temp->value); 
                    }
                    break;
            default:break;
        }
    }
    
    return 0; 
}
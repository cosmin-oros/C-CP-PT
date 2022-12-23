#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Consider a mail box that contains messagges. Each message is characterized by its priority (usual or urgent), destination, content. 
    An urgent message will always be placed on the first place of the mailbox, an an usual one will be placed such that usual messages are alphabetically ordered by destination. 
    Thus, the first positions will be UNORDERED, and only the usual messages will be ordered. A linked list will be used for all the messages. Implement the following operators:

    1.     Initialize() – initialize the mailbox – no messages

    2.     Send_message(priority, destination, content) – add a new message to the mailbox

    3.     Receive_message(destination) – the destination person will receive their highest priority message from the mailbox and the content will be displayed on the screen.

    4.     Display() – display the usual messages in reverse alphabetical order, after their destination
*/

typedef struct message {
    // isUrgent -> true (urgent), isUrgent -> false (usual)
    bool isUrgent;
    char destination[20];
    char content[20];
    struct message* next;
}MESSAGE;

// function for initializing the mailbox, no messages
MESSAGE* Initialize() {
    MESSAGE* mail_box = NULL;
    
    return mail_box;
}

// function for sending a new message
void Send_message(MESSAGE** mail_box, bool priority, char* destination, char* content) {
    MESSAGE* new_message = (MESSAGE*)malloc(sizeof(MESSAGE));

    // check if the mem was allocated
    if (!new_message)
    {
        printf("Couldn't allocate memory\n");
        return;
    }
    
    new_message->isUrgent = priority;
    strcpy(new_message->content, content);
    strcpy(new_message->destination, destination);

    // if the priority is urgent insert it at the start of the mailbox
    if (priority)
    {
        new_message->next = *mail_box;
        *mail_box = new_message;
    } else {
        MESSAGE* temp1 = NULL;
        MESSAGE* temp2 = *mail_box;

        // find the position where the new message should be put
        while (temp1 != NULL && (strcmp(temp2->destination, destination) != 0))
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        
        // insert the new message
        new_message->next = temp2;
        if (temp1 != NULL)
        {
            temp1->next = new_message;
        } else {
            *mail_box = new_message;    // if the new message should be inserted at the start
        }
        
    }

}

// function to receive the highest priority message for the destination provided
MESSAGE* Receive_message(MESSAGE** mail_box , char* destination) {
    MESSAGE* temp1 = NULL;
    MESSAGE* temp2 = *mail_box;

    // find the position where the destination appears first (highest priority)
    while (temp2 != NULL && (strcmp(temp2->destination, destination) != 0))
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    if (!temp2)
    {
        printf("Couldn't find the destination in the mailbox\n");
        return NULL;
    } else {
        printf("%s\n", temp2->content);
        return temp2;
    }
    
}

// function that inserts
void Insert_sorted(MESSAGE** mail_box, bool priority, char* destination, char* content)
{
    MESSAGE* new_message = malloc(sizeof(MESSAGE));

    // check if the mem was allocated
    if (!new_message)
    {
        printf("Couldn't allocate mem\n");
        return;
    }

    new_message->isUrgent = priority;
    strcpy(new_message->destination, destination);
    strcpy(new_message->content, content);

    // Find the position where the new message should be inserted
    MESSAGE* temp1 = NULL;
    MESSAGE* temp2 = *mail_box;
    while (temp2 != NULL && strcmp(temp2->destination, destination) < 0)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    // Insert the new message
    new_message->next = temp2;
    if (temp1 != NULL)
    {
        temp1->next = new_message;
    } else {
        *mail_box = new_message;
    }
}

// function that displays the usual messages from the mailbox in reverse alphabetical order, after their destination
void Display(MESSAGE** mail_box) {
    MESSAGE* temp = *mail_box;
    MESSAGE* sorted_messages = Initialize();

    // we only insert the usual messages in reverse alphabetical order
    while (temp != NULL)
    {
        if (!temp->isUrgent)
        {
            Insert_sorted(&sorted_messages, temp->isUrgent, temp->destination, temp->content);
        }

        temp = temp->next;
        
    }

    // display the sorted messages mailbox
    while (sorted_messages != NULL)
    {
        printf("%s\n", sorted_messages->content);
        sorted_messages = sorted_messages->next;
    }
    
}

int main() {
    MESSAGE* mail_box = Initialize();

    Send_message(&mail_box, true, "Timisoara", "blabla");
    Send_message(&mail_box, false, "Arad", "blabla2");
    Send_message(&mail_box, false, "Londra", "blabla3");
    Send_message(&mail_box, true, "New York", "blabla4");
    Send_message(&mail_box, false, "Paris", "blabla5");

    MESSAGE* message1 = Receive_message(&mail_box, "New York");

    Display(&mail_box);

    return 0;
}
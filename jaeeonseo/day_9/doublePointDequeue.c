void dequeue(queue **head, int data)
{
	queue *tmp = *head;

	if(*head == NULL)
		printf("There are no data that you delete\n");
	if((*head)->data != data)
		dequeue(&(*head)->link, data);
	else
	{
		printf("Now you delete %d\n", data);
		*head = tmp->link;
		free(tmp);
	}
}

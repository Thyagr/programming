using System;

public class Node
{
	public int data;
	public Node next;
	
	public Node(int value)
	{
		data = value;
		next = null;
	}
}

public class Program
{
	public static void Main()
	{
		Node head1 = null;
		Node head2 = null;
		int[] arr1 = {2, 3, 1};
		foreach (var i in arr1)
		{
			head1 = AddNode(head1, i);
		}

		int[] arr2 = {9, 3, 8};
		foreach (var i in arr2)
		{
			head2 = AddNode(head2, i);
		}

		Console.WriteLine("Linked list");
		PrintNodes(head1);
		PrintNodes(head2);

		Console.WriteLine("InterLeavedNodes");
		var head3 = InterleaveNodes(head1, head2);
		PrintNodes(head3);

		var head4 = SumOfDigits(head1, head2);
		PrintNodes(head4);
	}

	private static Node SumOfDigits(Node head1, Node head2)
	{
		/*
        can also use stack to store the linked list values instead of reversing
        */
		Node head = null;
		head1 = ReverseNodes(head1);
		head2 = ReverseNodes(head2);
		int sum = 0;
		int carry = 0;
		int digit;
		while (head1 != null && head2 != null)
		{
			int d1 = head1.data;
			int d2 = head2.data;
			sum = d1 + d2 + carry;
			digit = sum % 10;
			carry = sum / 10;
			head = AddNode(head, digit);
			head1 = head1.next;
			head2 = head2.next;
		}

		if (head1 == null)
		{
			while (head2 != null)
			{
				int d = head2.data;
				sum = d + carry;
				digit = sum % 10;
				carry = sum / 10;
				head2 = head2.next;
			}
		}

		if (head2 == null)
		{
			while (head1 != null)
			{
				int d = head1.data;
				sum = d + carry;
				digit = sum % 10;
				carry = sum / 10;
				head1 = head1.next;
			}
		}

		// final carry
		if (carry > 0) head = AddNode(head, carry);
		return ReverseNodes(head);
	}

	private static Node InterleaveNodes(Node head1, Node head2)
	{
		Node head = null;
		while (head1 != null && head2 != null)
		{
			head = AddNode(head, head1.data);
			head = AddNode(head, head2.data);
			head1 = head1.next;
			head2 = head2.next;
		}

		if (head1 == null)
		{
			while (head2 != null)
			{
				head = AddNode(head, head2.data);
				head2 = head2.next;
			}
		}

		if (head2 == null)
		{
			while (head1 != null)
			{
				head = AddNode(head, head1.data);
				head2 = head1.next;
			}
		}

		return head;
	}

	private static Node AddNode(Node head, int value)
	{
		Node node = new Node(value);
		if (head == null)
		{
			head = node;
		}
		else
		{
			Node cur = head;
			while (cur.next != null)
			{
				cur = cur.next;
			}

			cur.next = node;
		}

		return head;
	}

	private static Node ReverseNodes(Node head)
	{
		Node prv = null, nxt;
		while (head != null)
		{
			nxt = head.next;
			head.next = prv;
			prv = head;
			head = nxt;
		}

		head = prv;
		return head;
	}

	private static void PrintNodes(Node head)
	{
		Node cur = head;
		while (cur != null)
		{
			Console.Write( $"{cur.data} -> ");
			cur = cur.next;
		}

		Console.WriteLine("null");
	}
}
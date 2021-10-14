using System.Collections.Generic;

/*
Least Recently Used (LRU) cache
If the element exists in hashmap
    move the accessed element to the tail of the linked list
Otherwise,
    if eviction is needed i.e. cache is already full
        Remove the head element from the linked list and delete its hashmap entry
    Add the new element at the tail of linked list and in hashmap
Get from Cache and Return
 */

namespace LruArray
{
    public class LRU
    {
        readonly int capacity;
        List<int> items = null;
        HashSet<int> hashItems = null;

        public LRU(int c)
        {
            capacity = c;
            items = new List<int>();
            hashItems = new HashSet<int>();
        }

        public void Insert(int value)
        {
            // item already in cache 
            // move item to end of the list
            if (hashItems.Contains(value))
            {
                items.Remove(value);
                items.Add(value);
            }
            else
            {
                // if at capacity then remove first element in list and delete from cache  
                // add new item to list end and cache
                if (items.Count == capacity)
                {
                    hashItems.Remove(items[0]);
                    items.RemoveAt(0);
                }
                
                items.Add(value);
                hashItems.Add(value);
            }
        }

        public bool IsItemInCache(int value)
        {
            return hashItems.Contains(value);
        }
    }
}

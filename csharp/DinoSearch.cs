
private static void PrintDinos(string file1, string file2)
{
	var dinoDictList = new List<Dictionary<string, string>>();
	using (var sr = new StreamReader(file2))
	{
		string line;
		while ((line = sr.ReadLine()) != null)
		{
			var splitLine = line.Split(',');
			var dict = new Dictionary<string, string>();
			dict["Name"] = splitLine[0];
			dict["STRIDE_LENGTH"] = splitLine[1];
			dict["STANCE"] = splitLine[2];
			dinoDictList.Add(dict);
		}
	}
	
	using (var sr = new StreamReader(file2))
	{
		string line;
		while ((line = sr.ReadLine()) != null)
		{
			var splitLine = line.Split(',');
			var dict = dinoDictList.Find(d => d.ContainsKey(splitLine[0]));
			dict["LEG_LENGTH"] = splitLine[1];
			dict["DIET"] = splitLine[2];
		}
	}
	
	foreach (var d in dinoDictList)
	{
		if (d["STANCE"] == "bipedal")
		{
			var speed = 0; // formula
		}
	}
	
	var bipedals = dinoDictList.Select(d => d["STANCE"] == "bipedal")
	bipedals.Sort(d => d["LEG_LENGTH"]);
	
	var x =  bipedals.Keys.ToList();
	
}


private static void Hello(int[] arr)
{
	var dict = new Dictionary<char, int>();
	var s1 = "waterbottle";
	
	foreach (var item in s1)
	{
		if (dict.ContainsKey(item)
			dict[item] += 1;
		else
			dict[item] = 1;
	}
	
	string s2 = "lewaterbott";
	var dict2 = new Dictionary<char, int>();
	
	foreach (var item in s1)
	{
		if (dict2.ContainsKey(item))
			dict[item] += 1;
		else
			dict2[item] = 1;
	}
	
	// var hash = new HashSet<string> {s1};
	// var hash2 = new HashSet<string> {s2};
	
	// hash.
	
	return dict.Count == dict2.Count 
	&& dict.Except(dict2).Any();
	
	
		
}
def longest_substring_in_order(word):
    longest_substring = ""
    candidate = ""
    candidates=[]
    in_order = False
    for i in range(0,len(word)):
        if i<len(word)-1:
            if word[i]<word[i+1]:
                in_order = True
                #print(in_order)
                print("Ok")
                candidate = candidate+word[i]
            else:
                print("No")
                candidates.append(candidate)
        else:
            if word[i-1]<word[i]:
                print("ok end")
                pass
    
    for c in candidates:
        print("Candidates are\n",c)

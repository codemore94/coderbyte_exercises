def longest_substring_in_order(word):
<<<<<<< HEAD
    """
    Find the longest substring in the alphabetic order of given string.

    :param word: str, the word from which the longest substring is found
    :return: the longest substring
    """
    longest_substring = ""
    candidate = ""
    candidates=[]
    one_length_sub_string = False
    if len(word) ==1 or word == "" or len(word) == 0:
        return word
    
    for i in range(0,len(word)):
        if i<len(word)-1:
            if word[i]<word[i+1]:
                candidate = candidate+word[i]
                print("word at now1",candidate)
            else:
                candidate = candidate+word[i]
                print("word at now2",candidate)
                candidates.append(candidate)
                candidate = ""
                print("B")
        elif i == len(word)-1:
            if word[i-1]<word[i]:
                candidate = candidate+word[i]
                print("C")
            else:
                #candidate = candidate+word[i-1]
                candidates.append(candidate)
                candidate = ""
                print("D")
    print("debug0011",len(candidates))

    #if len(candidates) == 0:
        #return candidate
    
    if len(candidates) == 1 or len(candidates) == 0:
        print("AABB",candidates[0])
        if len(candidates)!=0:
            longest_substring = candidates[0]
        else:
            longest_substring = candidate
        return longest_substring
    for j in range(0,len(candidates)):
        if len(candidates[j]) == 1:
            one_length_sub_string = True
        if j < len(candidates)-1:
            if len(candidates[j])<len(candidates[j+1]):
                print("candouou",candidates[j+1])
                if len(longest_substring)>len(candidates[j+1]):
                    pass
                else:
                    longest_substring = candidates[j+1]
            else:
                pass
        elif j == len(candidates)-1:
            if len(candidates[j-1])<len(candidates[j]):
                if len(longest_substring)>len(candidates[j]):
                    pass
                else:
                    longest_substring = candidates[j]
            else:
                pass
    #for k on range(0,len(candidates)):
        #print("CANDO",candidates[k])
    if one_length_sub_string:
        return candidates[0]
    return longest_substring
=======
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
>>>>>>> 2222d2f380a9131fcabfc02a007b342d88038c26

def reverse_name(name):
    """.
    :param name: string, the name with possible spaces and dots.
    :ret fullname: string, the name from which deleted spaces and dots
    """
    fullname = ""
    tmp_name = ""
    names=[]
    in_space = False #in the beginning in no state
    in_dot = False
    in_word = False
    
    for i in range(0,len(name)): #there are two possibilities to be outside word: space or ,. Otherwise we are inside the word.While inside the word concatenate the char to tmp_name. While outside just skip char and increment counter.
        if name[i] == " " or name[i] == ",":
            if name[i] == " " and in_space == False: #in_space
                in_space = True
                in_dot = False
                in_word = False
                #print("in_space",tmp_name)
                if not(tmp_name in names) and tmp_name != "":
                    #print("Adding unseen word")
                    names.append(tmp_name)
                #for n in range(0,len(names)):
                    #print("in_space2",names[n])

            elif name[i] == " " and in_space == True : #in_space
                pass
            elif name[i] == "," and in_dot == False: # in_dot
                in_space = False
                in_dot = True
                in_word = False
                #print("in_dot",tmp_name)
                if not(tmp_name in names):
                    names.append(tmp_name)
                #for n in range(0,len(names)):
                    #print("in_dot",names[n])
                if len(names)>1:
                    tmp_word = names[0] + " " + names[1]
                    #print(tmp_word)
            elif name[i] == "," and in_dot == True: # in_dot
                pass
        elif not(name[i] == " " or name[i] == ","):#in_word
            if in_space == True or in_dot == True:
                tmp_name = ""
            in_space = False
            in_dot = False
            in_word = True
            tmp_name += name[i] 
            #print("in_word",tmp_name)
    if not(tmp_name in names):
        names.append(tmp_name)        
    #for m in range(0,len(names)):
        #print("at list",names[m])
        #print(len(names))
        
    #if len(names)<=2:
    if len(names)>1 and (len(names)<3 and names[1] == "Student"):
        #print("Böö")
        j = len(names)-1 #len(names) == 2
        while j >= 0:
            #print("word2_names2",names[j])
            if j == len(names)-1:
                word = names[j-1]
            elif j == len(names)-2:
                word = names[j+1]  #names[2],names[1],names[0]"
            #if j == len(names)-3:
                #word = names[j+1] 
            for k in range(0,len(word)):
                if word[k] == " " or word[k] == ",":
                    pass
                else:
                    #print("words2: ",word[k])
                    if len(names) == 1 and len(word) == 1:#one char
                        fullname=fullname+word[k]
                    else:
                        if j == len(names)-1 or j == len(names)-2:
                            fullname=fullname+word[k]
                        else:
                            fullname=fullname+word[k]
            if (j == len(names)-1) and len(tmp_name)>1: #and len(names)>2:
                fullname += " "
                            #fullname+=word[k] 
            j = j-1
        
    elif len(names)<3:
        #print("Dangerous begins")
        j = len(names)-1
        while j >= 0:
            word = names[j]
            for k in range(0,len(word)):
                if word[k] == " " or word[k] == ",":
                    pass
                else:
                    #print("words: ",word[k])
                    if len(names) == 1 and len(word) == 1:
                        fullname=fullname+word[k]
                    else:
                        if j == len(names)-1 and len(names[0]) == 1:
                            fullname=fullname+word[k]+" "
                        else:
                            fullname+=word[k]        
            if j == len(names)-1 and len(tmp_name)>1 and len(names)>1:
                fullname += " "
            
            j = j-1
            #print("Dangerous ends")




    #if len(names)<3:
        #j = len(names)-1
        #while j >= 0:
            #word = names[j]
            #for k in range(0,len(word)):
                #if word[k] == " " or word[k] == ",":
                    #pass
                #else:
                    #print("words: ",word[k])
                    #if len(names) == 1 and len(word) == 1: #basically one char like 'X'
                        #fullname=fullname+word[k]
                    #else:
                        #if j == len(names)-1 and len(names[0]) == 1: #forname from the end of list to the first
                            #fullname=fullname+word[k]
                        #else:
                            #fullname+=word[k]        
            #if j == len(names)-1 and len(tmp_name)>1: #and len(names)>2:
                #fullname += " "
            
            #j = j-1
    else:
        #if names[0] == "von" and names[1] == "Grünbaumberger":
            #pass
        #pass
        j = len(names)-1 #len(names) == 2
        while j >= 0:
            #print("word2_names2",names[j])
            if j == len(names)-1:
                word = names[j]
            if j == len(names)-2:
                word = names[j-1]  #names[2],names[1],names[0]"
            if j == len(names)-3:
                word = names[j+1] 
            for k in range(0,len(word)):
                if word[k] == " " or word[k] == ",":
                    pass
                else:
                    #print("words2: ",word[k])
                    if len(names) == 1 and len(word) == 1:#one char
                        fullname=fullname+word[k]
                    else:
                        if j == len(names)-1 or j == len(names)-2:
                            fullname=fullname+word[k]
                        else:
                            fullname=fullname+word[k]
                        #elif j == len(names)-2:
                            #word = names[j-1]
                            #fullname=fullname+word[k]+" "
                        #elif j == len(names)-3:
                            #word = names[j+1]
                            #fullname=fullname+word[k]
                            #for k in range(0,len(word)-1):
                        #if j == len(names)-2:
                            #word = names[j-1]
                            #for k in range(0,len(word)-1):
                                #if word[k] == " " or word[k] == ",":
                                   #pass
                                #else:
                                   #print("words2: ",word[k])
                                   #if len(names) == 1 and len(word) == 1:
                                       #fullname=fullname+word[k]
                                   #else:
                                       #pass
                            #if j == len(names)-1 and len(names[0]) == 1: 
                                 #fullname=fullname+word[k]+" "
                            #elif j == len(names)-2:
                                 #fullname+=word[k]        
                            #if j == len(names)-1 or j == len(names)-2 and len(tmp_name)>1:
                                #fullname += " "
                        #if j == 0:
                            #word = names[j+1]
                            #for k in range(0,len(word)):
            if (j == len(names)-1 or j == len(names)-2) and len(tmp_name)>1: #and len(names)>2:
                fullname += " "
                            #fullname+=word[k] 
            j = j-1
        
    return fullname

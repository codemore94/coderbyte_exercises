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
                print("in_space",tmp_name)
                if not(tmp_name in names):
                    print("Adding unseen word")
                    names.append(tmp_name)
                for n in range(0,len(names)):
                    print("in_space2",names[n])

            elif name[i] == " " and in_space == True : #in_space
                pass
            elif name[i] == "," and in_dot == False: # in_dot
                in_space = False
                in_dot = True
                in_word = False
                print("in_dot",tmp_name)
                if not(tmp_name in names):
                    names.append(tmp_name)
                for n in range(0,len(names)):
                    print("in_dot",names[n])

            elif name[i] == "," and in_dot == True: # in_dot
                pass
        elif not(name[i] == " " or name[i] == ","):#in_word
            if in_space == True or in_dot == True:
                tmp_name = ""
            in_space = False
            in_dot = False
            in_word = True
            tmp_name += name[i]
            print("in_word",tmp_name)
    if not(tmp_name in names):
        names.append(tmp_name)        
    for m in range(0,len(names)):
        print("at list",names[m])
        
    #if len(names)<=2:
    j = len(names)-1
    while j >= 0:
        word = names[j]
        for k in range(0,len(word)):
            if word[k] == " " or word[k] == ",":
                pass
            else:
                print("words: ",word[k])
                if len(names) == 1 and len(word) == 1:
                    fullname=fullname+word[k]
                else:
                    if j == len(names)-1 and len(names[0]) == 1:
                        fullname=fullname+word[k]+" "
                    else:
                        fullname+=word[k]        
        if j == len(names)-1 and len(tmp_name)>1: #and len(names)>2:
            fullname += " "
            
        j = j-1
    #elif len(names)>2:
        #j = len(names)-1
        #while j >= 0:
            #word = names[j]
            #for k in range(0,len(word)):
                #if word[k] == " " or word[k] == ",":
                    #pass
                #else:
                    #print("words2: ",word[k])
                    #if len(names) == 1 and len(word) == 1:
                        #fullname=fullname+word[k]
                    #else:
                        #if j == len(names)-1 and len(names[0]) == 1:
                            #fullname=fullname+word[k]+" "
                        #if j == len(names)-2:
                            #word = names[j-1]
                            #for k in range(0,len(word)):
                                #if word[k] == " " or word[k] == ",":
                                   #pass
                                #else:
                                   #print("words2: ",word[k])
                             #if len(names) == 1 and len(word) == 1:
                                #fullname=fullname+word[k]
                             #else:
                             #if j == len(names)-1 and len(names[0]) == 1:
                            #fullname=fullname+word[k]+" "
                        #elif j == len(names)-2:
                                   #fullname+=word[k]        
                                   #if j == len(names)-1 or j == len(names)-2 and len(tmp_name)>1:
                                   #fullname += " "
                        #if j == 0:
                            #word = names[j-1]
                            #for k in range(0,len(word)):
                                #fullname+=word[k] 
            #j = j-1
        
    return fullname

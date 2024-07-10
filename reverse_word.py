
def reverse_name(name):
    """.
    :param name: string, the name with possible spaces and dots.
    :ret fullname: string, the name from which deleted spaces and dots
    """
    fullname = ""
    tmp_name = ""
    names=[]
    in_space = False
    in_dot = False
    in_word = False
    
    for i in range(0,len(name)): #there are two possibilities to be outside word: space or ,. Otherwise we are inside the word.While inside the word concatenate the char to tmp_name. While outside just skip char and increment counter.
        #print(name[i])
        if name[i] == " " or name[i] == ",":
            if name[i] == " " and in_space == False: #in_space
                #print("space,in_space false")
                in_space = True
                in_dot = False
                in_word = False  
                #names.append(tmp_name)
                #tmp_name = ""
            elif name[i] == " " and in_space == True : #in_space
                pass
                #names.append(tmp_name)
            elif name[i] == "," and in_dot == False: # in_dot
                in_space = False
                in_dot = True
                in_word = False
                names.append(tmp_name)
                #print("in_dot_first",tmp_name)
                #tmp_name = ""
            elif name[i] == "," and in_dot == True: # in_dot
               # names.append(tmp_name)
                pass
        elif not(name[i] == " " or name[i] == ","):#in_word
            if in_space == True or in_dot == True:
                tmp_name = ""
            #print("what",name[i])
            in_space = False
            in_dot = False
            
            tmp_name += name[i]
            #print(tmp_name)
    names.append(tmp_name)        
    #print(names)
    j = len(names)-1
    while j >= 0:
        word = names[j]
        for k in range(0,len(word)):
            if word[k] == " " or word[k] == ",":
                pass
            else:
                fullname+=word[k]
        if j == len(names)-1:
            fullname += " "
                #fullname = "'"+fullname+"'"
        j = j-1        
    #print(fullname)            
    return fullname

def is_peledrome():
    word=input("enter the word-")
    peledrome='false'
    start = 0
    end = len(word) - 1
    for i in range(len(word)//2):
        if(word[start]==word[end]):
            start=start+1
            end=end-1
            peledrome='true'
        else:
            break
    return peledrome
print(is_peledrome())
    
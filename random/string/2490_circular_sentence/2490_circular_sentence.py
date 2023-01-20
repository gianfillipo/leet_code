class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        list_words=sentence.split(" ")

        first_word=list_words[0]
        last_word=list_words[len(list_words)-1]

        if first_word[0] != last_word[len(last_word)-1]:
            return False

        for i in range(len(list_words)-1):
            if list_words[i][len(list_words[i])-1].lower() != list_words[i+1][0].lower():
                return False
            
        return True

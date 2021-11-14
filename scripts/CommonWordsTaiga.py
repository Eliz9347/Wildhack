import gensim

print("Please insert path to search_history")
# G:/WildHack/noun_tayga_1_2.vec
model_path = input()
model_ru = gensim.models.KeyedVectors.load_word2vec_format(model_path, binary=False)

words = ['день', 'ночь']
common_words = []

for word in words:
    # есть ли слово в модели? 
    if word in model_ru:
        for i in model_ru.most_similar(positive=[word], topn=10):
            # слово + коэффициент косинусной близости
            common_words.append({i[0], i[1]})
    else:
        print('Cлова "%s" в модели нет!' % word)

print(common_words)
from django.shortcuts import render
from django.template import loader
from django.http import JsonResponse


# поиск
def index(request):
    if request.method == "POST":
        query = request.POST.get("query")
        tags = ['жакет', 'пиджак', 'жилет']

        return render(request, 'tags_app/wb_front/index.html', {'tags': tags})
    else:
        return render(request, 'tags_app/wb_front/index.html')


# отправка тегов
def ajax_tags(request):
    print("receive cat")
    # case_cat = request.GET.get('cat_id')
    # subcats = cats_for_cases.get_subcats(case_cat)
    # subs = {'list': subcats}
    # # print(subs)
    # return JsonResponse(subs)
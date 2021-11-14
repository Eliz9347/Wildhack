from django.urls import path

from . import views


urlpatterns = [
    path('', views.index, name='index'),
    path('ajax_tags', views.ajax_tags, name='ajax_tags'),
]
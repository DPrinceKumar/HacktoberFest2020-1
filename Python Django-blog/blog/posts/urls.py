from django.urls import path, include
from .views import (
    PostCreateView,
    PostDeleteView,
    PostDetailView,
    PostListView,
    PostUpdateView,
    like_post
)

app_name = 'posts'

urlpatterns = [
    path('',PostListView.as_view(),name='post_list'),
    path('create/',PostCreateView.as_view(),name='post_create'),
    path('<slug>/',PostDetailView.as_view(),name='post_detail'),
    path('<slug>/delete/',PostDeleteView.as_view(),name='post_delete'),
    path('<slug>/update/',PostUpdateView.as_view(),name='post_update'),
    path('like/<slug>',like_post,name='like_post')   
]
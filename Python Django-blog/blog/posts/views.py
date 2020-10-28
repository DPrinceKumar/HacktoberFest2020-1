
from django.shortcuts import render,redirect, reverse, get_object_or_404
from django.views.generic import ListView, DetailView, CreateView, UpdateView, DeleteView
from django.contrib.auth.mixins import LoginRequiredMixin
from .models import Post,PostView, Comment, Like, User
from .forms import PostForm, CommentForm
# Create your views here.

class PostListView(ListView):
    model = Post
    template_name = 'post_list.html'

class PostDetailView(DetailView):
    model = Post

    def post(self,*args, **kwargs):
        form = CommentForm(self.request.POST)
        if form.is_valid():
            post = self.get_object()
            comment = form.instance
            comment.user = self.request.user
            comment.post = post
            comment.save()
            return redirect('posts:post_detail',slug=post.slug)
        return redirect('posts:post_detail',slug=post.slug)

    def get_context_data(self,**kwargs):
        context = super().get_context_data(**kwargs)
        context['form'] = CommentForm()
        return context

    def get_object(self,**kwargs):
        object = super().get_object(**kwargs)
        if self.request.user.is_authenticated:
            PostView.objects.get_or_create(user=self.request.user,post=object)
        return object

class PostCreateView(LoginRequiredMixin,CreateView):
    form_class = PostForm
    model = Post

    def form_valid(self,form):
        form.instance.author = self.request.user
        return super().form_valid(form)

    def get_context_data(self,**kwargs):
        context = super().get_context_data(**kwargs)
        context['view_type'] = 'Create'
        return context
    
    def get_success_url(self):
        return reverse('posts:post_detail', kwargs={ 'slug': self.object.slug})

class PostUpdateView(UpdateView):
    model = Post
    form_class = PostForm

    def get_context_data(self,**kwargs):
        context = super().get_context_data(**kwargs)
        context['view_type'] = 'Update'
        return context
    # fields = [
    #     'title',
    #     'content',
    #     'thumbnail',
    #     'author',
    #     'slug'
    # ]

    def get_success_url(self):
        return reverse('posts:post_detail', kwargs={ 'slug': self.kwargs['slug']})

class PostDeleteView(DeleteView):
    model = Post
    success_url = '/'

def like_post(request, slug):
    print(request.user)
    post = get_object_or_404(Post,slug=slug)
    like_qs = Like.objects.filter(user=request.user,post=post)
    if like_qs.exists():
        like_qs[0].delete()
    else:
        Like.objects.create(user=request.user,post=post)   
    return redirect('posts:post_detail',slug=slug)

# class Comment
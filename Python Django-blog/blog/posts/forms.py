from django import forms
from .models import Post, Comment

class PostForm(forms.ModelForm):
    class Meta:
        model = Post
        # fields = ('__all__')
        exclude = ['author']

class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        fields = ('content', )
        widgets = {
            'content': forms.Textarea(attrs=
            {   
                'rows':2,
                'placeholder':"Write a comment"
                }
            )
        }
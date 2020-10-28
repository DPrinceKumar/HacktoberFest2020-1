from django.contrib import admin
from .models import (
    Post,
    PostView,
    Comment,
    Like,
    User
)

# Register your models here.
@admin.register(Post)
class PostAdmin(admin.ModelAdmin):
    pass

@admin.register(PostView)
class PostViewAdmin(admin.ModelAdmin):
    pass

@admin.register(Comment)
class CommentAdmin(admin.ModelAdmin):
    pass

@admin.register(Like)
class LikeAdmin(admin.ModelAdmin):
    pass

@admin.register(User)
class UserAdmin(admin.ModelAdmin):
    pass
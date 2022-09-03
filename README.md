# PBR渲染器

## 物体添加删除 待定

## 天空盒

1.6个面
-------top------------------
left---front---right----back
-------bottom---------------
left    GL_TEXTURE_CUBE_MAP_POSITIVE_X
RIGHT   GL_TEXTURE_CUBE_MAP_NEGATIVE_X
top     GL_TEXTURE_CUBE_MAP_POSITIVE_Y
bottom  GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
back    GL_TEXTURE_CUBE_MAP_POSITIVE_Z
front   GL_TEXTURE_CUBE_MAP_NEGATIVE_Z

2.天空盒边缘混合

3.天空盒使用
x,y,z 最大值确定使用那一个面，剩下两维度确定面坐标
最后时候才绘制天空盒
天空盒深度应该是最深的，这样整个天空才能显示
天空盒应该接收摄像机视角方向来采样

## 属性调整
### 世界大小调整 画面大小
### 物体调整 平移旋转缩放
### camera调整 平移旋转
### 投影矩阵调整 正交/透视

## 光照 brdf 渲染方程
### 金属度
### 粗糙度

## 阴影
### shadowmap
### pcss

## 后处理
### 抗锯齿
### HDR

## 性能优化
### 可见性
### 帧率

## UI编辑器

## FBX,OBJ支持
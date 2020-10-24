 cat("\nStep 2: Variable Declaration")
modelFileName <- "neuralNetwork-Model.RData"
#testFileName  <-"test.csv"



#--------------------------------------------------------------
# Step 3: Model Loading
#--------------------------------------------------------------
cat("\nStep 3: Model Loading")
load(modelFileName)



#--------------------------------------------------------------
# Step 4: Data Loading
#--------------------------------------------------------------
library(EBImage)
Image <- readImage('three.jpg')
#print(Image)
#display(Image)

#colorMode(Image) <- Grayscale


#-------------------------------------------------------------
cat("\nStep 4: Data Loading")
#image=readJPEG('4.jpg')
nof=numberOfFrames(Image, type = c('total', 'render'))
if(nof==1)
{
  image=255*imageData(Image[1:28,1:28])
}else 
  if(nof==3)
  {
    r=255*imageData(Image[1:28,1:28,1])
    g=255*imageData(Image[1:28,1:28,2])
    b=255*imageData(Image[1:28,1:28,3])
    #--------RGB TO GREYSCALE--------#
    # uptil now
    image=0.21*r+0.72*g+0.07*b
    #image=(r+g+b)/3
    #image=0.2989*r+0.5870*g+0.1140*b
    #chk 0.2989, 0.5870, 0.1140. chk Red * 0.3 + Green * 0.59 + Blue * 0.11
    image=round(image)
  }


image=t(image)

#only to check pixel values of image
  write.csv(image,'chkimg.csv',row.names = FALSE)
#------------upper line only----------------
image=as.vector(t(image))
write.csv(t(as.matrix(image)),'threepx.csv',row.names = FALSE)
testFileName  <-'threepx.csv'
newTestDataset <- read.csv(testFileName)    # Read the datafile
head(newTestDataset)


testreduced <- newTestDataset/255 
#Xcov <- cov(testreduced)
#pcaX <- prcomp(Xcov)
testreduced <- as.matrix(testreduced) %*% pcaX$rotation[,1:45]


#--------------------------------------------------------------
# Step 5: Prediction (Testing)
#--------------------------------------------------------------
cat("\nStep 5: Prediction using -> ", modelName)
library(nnet)
NewPredicted <- predict(model,testreduced,type="class")
NewPredicted <- as.data.frame(NewPredicted);
head(NewPredicted)


#--------------------------------------------------------------
# Step 6: Saving Results
#--------------------------------------------------------------
cat("\nStep 6: Saving Results")
write.csv(data.frame(newTestDataset,NewPredicted), file=paste(modelName,"-Testing-Result.csv",sep=''), row.names=FALSE)


cat("\nDone")

#--------------------------------------------------------------
#                           END 
#--------------------------------------------------------------


cat("\nSTART\n")
startTime = proc.time()[3]
startTime

library(nnet)

modelName <- "neuralNetwork"
InputDataFileName="mnist_train.csv"

trainDataset <- read.csv(InputDataFileName)      # Read the datafile
trainDataset <- trainDataset[sample(nrow(trainDataset)),]  # Shuffle the data row wise

head(trainDataset)   # Show Top 6 records
nrow(trainDataset)   # Show number of records
names(trainDataset)  # Show fields names or columns names

#--------------------------------------------------------------
# Step 5: Choose Target variable
#--------------------------------------------------------------
cat("\nStep 5: Choose Target Variable")
target  <- names(trainDataset)[1] #label name
target



#--------------------------------------------------------------
# Step 6: Choose inputs Variables
#--------------------------------------------------------------
cat("\nStep 6: Choose Inputs Variable")
inputs <- setdiff(names(trainDataset),target)
inputs
length(inputs)
#--------------------------------------------------------------
# Step 7: Select Training Data Set
#--------------------------------------------------------------
cat("\nStep 7: Select training dataset")

head(trainDataset)    # Show Top 6 records
nrow(trainDataset)    # Show number of train Dataset

X=trainDataset[,-1] # contains all pixels value
Y=trainDataset[,1] # labels only
Xreduced <- X/255

Xcov <- cov(Xreduced)
pcaX <- prcomp(Xcov)

Xfinal <- as.matrix(Xreduced) %*% pcaX$rotation[,1:45]
Y <- class.ind(Y)

#--------------------------------------------------------------
# Step 8: Select Testing Data Set
#--------------------------------------------------------------
cat("\nStep 8: Select testing dataset")
testDataset <- read.csv("mnist_test.csv")
head(testDataset)
nrow(testDataset)

test=testDataset[,-1]
testreduced <- test/255 
testreduced <- as.matrix(testreduced) %*% pcaX$rotation[,1:45]
#write.csv(testDataset,file="testDataset.csv",row.names=FALSE);
#--------------------------------------------------------------
# Step 9: Model Building (Training)
#--------------------------------------------------------------
cat("\nStep 9: Model Building -> ", modelName)
#formula <- as.formula(paste(target, "~", paste(c(inputs), collapse = "+")))
#formula

#model   <- nnet(formula, trainDataset, size=10, linout=TRUE, skip=TRUE, MaxNWts=10000, trace=FALSE, maxit=100,softmax=TRUE)
model <- nnet(Xfinal,Y,size=150,softmax=TRUE,maxit=130,MaxNWts =80000)
model

#--------------------------------------------------------------
# Step 10: Prediction (Testing)
#--------------------------------------------------------------
cat("\nStep 10: Prediction using -> ", modelName)
Predicted <- predict(model, testreduced,type="class")
Predicted <- as.data.frame(Predicted);
head(Predicted) 


#--------------------------------------------------------------
# Step 11: Extracting Actual
#--------------------------------------------------------------
cat("\nStep 11: Extracting Actual")
Actual <- as.double(unlist(testDataset[target]))
head(Actual)



#--------------------------------------------------------------
# Step 12: Model Evaluation
#--------------------------------------------------------------
cat("\nStep 12: Model Evaluation")

# Step 12.1: Accuracy
accuracy <- round(mean(Actual==Predicted) *100,2)
accuracy


# Step 12.2: Total Time
totalTime = proc.time()[3] - startTime
totalTime


# Step 12.3: Save evaluation resut 
result <- data.frame(modelName,accuracy, totalTime)[1:1,]
result



#--------------------------------------------------------------
# Step 13: Writing to file
#--------------------------------------------------------------
cat("\nStep 13: Writing to file")

# Step 13.1: Writing to file (evaluation result)
write.csv(result, file=paste(modelName,"-Evaluation-Result.csv",sep=''), row.names=FALSE)

# Step 13.2: Writing to file (Actual and Predicted)
write.csv(data.frame(Actual,Predicted), file=paste(modelName,"-ActualPredicted-Result.csv",sep=''), row.names=FALSE)



#--------------------------------------------------------------
# Step 14: Saving the Model
#--------------------------------------------------------------
cat("\nStep 14: Saving the Model ->",modelName)
save.image(file=paste(modelName,"-Model.RData",sep=''))


cat("\nDone")
cat("\nTotal Time Taken: ", totalTime," sec")


#--------------------------------------------------------------
#                           END 
#--------------------------------------------------------------



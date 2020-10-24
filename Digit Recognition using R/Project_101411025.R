modelFileName <- "neuralNetwork-Model.RData"
library(shiny)
library(EBImage)
library(nnet)
load(modelFileName)

ui <- fluidPage(
  
  #input()
  fileInput(inputId = "image","Choose a Image",multiple = FALSE,accept = c('image/png', 'image/jpeg')),
  #output()
  textOutput("digit"),
  imageOutput("myImage")
)

server <- function(input, output) {
  
  output$digit <- renderText({
    
    inFile <- input$image
    
    if (is.null(inFile))
      return(NULL)
    
    old = inFile$datapath
    new = file.path(dirname(inFile$datapath),
                         inFile$name)
    file.rename(from = old, to = new)
    inFile$datapath <- new
    
    Image <- readImage(inFile$datapath)
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
    #write.csv(image,'chkimg.csv',row.names = FALSE)
    
    image=as.vector(t(image))
    write.csv(t(as.matrix(image)),'threepx.csv',row.names = FALSE)
    testFileName  <-'threepx.csv'
    newTestDataset <- read.csv(testFileName)    # Read the datafile
    testreduced <- newTestDataset/255 
    #Xcov <- cov(testreduced)
    #pcaX <- prcomp(Xcov)
    testreduced <- as.matrix(testreduced) %*% pcaX$rotation[,1:45]
    NewPredicted <- predict(model,testreduced,type="class")
    #NewPredicted <- as.data.frame(NewPredicted);
    paste("Predicted Value is",NewPredicted)
  })
  
  output$myImage <- renderImage({
    # A temp file to save the output.
    # This file will be removed later by renderImage
    inFile <- input$image
    if (is.null(inFile))
      return(NULL)
    
    outfile <- tempfile(fileext='.jpg')
    
    old = inFile$datapath
    new = file.path(dirname(inFile$datapath),
                    inFile$name)
    file.rename(from = old, to = new)
    inFile$datapath <- new
    
    # Return a list containing the filename
    list(src = inFile$datapath,
         contentType = 'image/jpeg',
         width = 200,
         height = 200,
         alt = "Predicted image")
  }, deleteFile = TRUE)
}

shinyApp(ui = ui, server = server)
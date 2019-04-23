mycam=imaq.VideoDevice('winvideo');
mycam.VideoFormat='MJPG_640x480';
mycam.ReturnedDataType='uint8';
diskElem=strel('disk',3);
hBlob = vision.BlobAnalysis('MinimumBlobArea',2000,'MaximumBlobArea',50000);
vidPlayer = vision.DeployableVideoPlayer;
for i=1:1000
    videoframe=step(mycam);
    I = videoframe;
    
    % Define thresholds for channel 1 based on histogram settings
    channel1Min = 66.000;
    channel1Max = 189.000;
    
    % Define thresholds for channel 2 based on histogram settings
    channel2Min = 0.000;
    channel2Max = 55.000;
    
    % Define thresholds for channel 3 based on histogram settings
    channel3Min = 4.000;
    channel3Max = 63.000;
    
    % Create mask based on chosen histogram thresholds
    sliderBW = (I(:,:,1) >= channel1Min ) & (I(:,:,1) <= channel1Max) & ...
        (I(:,:,2) >= channel2Min ) & (I(:,:,2) <= channel2Max) & ...
        (I(:,:,3) >= channel3Min ) & (I(:,:,3) <= channel3Max);
    BW = sliderBW;
    IBW=imopen(BW,diskElem);
    [areaOut,centroidOut,bboxOut] = step(hBlob,IBW);
    Ishape = insertShape(videoframe,'Rectangle',bboxOut,'Linewidth',4);
    Itext = insertText(Ishape,[centroidOut(:,1) centroidOut(:,2)],sprintf('%0.5f , ',centroidOut(:,1),...
        centroidOut(:,2)));
    step(vidPlayer,Itext);
end
release(mycam)

    
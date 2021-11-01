# #progrm to send an email

# import smtplib 
# from email.mime.multipart import MIMEMultipart 
# from email.mime.text import MIMEText 
# from email.mime.base import MIMEBase 
# from email import encoders

# mail_content = '''Hello, This is a test mail. In this mail we are sending some attachments. The mail is sent using Python SMTP library. Thank You ''' 

# #The mail addresses and password 
# sender_address = 'ymounikab@gmail.com' 
# sender_pass = 'Mounika@90' 
# receiver_address = 'ymounikab1@gmail.com' 

# #Setup the MIME 
# message = MIMEMultipart() 
# message['From'] = sender_address 
# message['To'] = receiver_address 
# message['Subject'] = 'A test mail sent by Python. It has an attachment.' 

# #The subject line 
# #The body and the attachments for the mail 

# message.attach(MIMEText(mail_content, 'plain')) 
# attach_file_name = 'F:\\Training\\mailtext.txt' 
# attach_file = open(attach_file_name, 'rb') 

# # Open the file as binary mode 

# payload = MIMEBase('application', 'octate-stream') 
# payload.set_payload((attach_file).read()) 
# encoders.encode_base64(payload) 

# #encode the attachment 
# #add payload header with filename 

# payload.add_header('Content-Decomposition', 'attachment', filename=attach_file_name) 
# message.attach(payload) 

# #Create SMTP session for sending the mail 

# session = smtplib.SMTP('smtp.gmail.com', 587) 

# #use gmail with port 

# session.starttls() 

# #enable security 

# session.login(sender_address, sender_pass) 

# #login with mail_id and password 

# text = message.as_string() 
# session.sendmail(sender_address, receiver_address, text) 
# session.quit() 
# print('Mail Sent')

# sending mail using python 

import smtplib
import datetime as dt
import time
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

def send_email():
	senderEMailAddress = "ymounikab@gmail.com"
	recieverEMailAddress = "ravi_pendyala@tecnics.com"
	fileName = "F:\\Training\\mailtext.txt"
	attachmentName = "tecnics.png"
	attachmentPath = "F:\\Training\\tecnics.png"

	fData = open(fileName, "r")
	subject = fData.readline()
	fileData = fData.read()

	message = MIMEMultipart()
	message["From"] = senderEMailAddress
	message["To"] = recieverEMailAddress
	message["Subject"] = subject
	bodyContent = fileData
	message.attach(MIMEText(bodyContent, 'plain'))

	filename = attachmentName 
	attachment = open(attachmentPath, "rb")
	p = MIMEBase('application', 'octet-stream')
	p.set_payload((attachment).read())
	encoders.encode_base64(p)
	p.add_header('Content-Disposition', "attachment; filename= %s" % filename)
	message.attach(p)

	smtpSession = smtplib.SMTP('smtp.gmail.com', 587)
	smtpSession.starttls()
	smtpSession.login(senderEMailAddress, "Mouni@90&")
	text = message.as_string()
	smtpSession.sendmail(senderEMailAddress, recieverEMailAddress, text)
	smtpSession.quit()
send_time = dt.datetime(2021,11,1,12,45,0) # set your sending time in UTC
time.sleep(send_time.timestamp() - time.time())
send_email()
print('email sent')
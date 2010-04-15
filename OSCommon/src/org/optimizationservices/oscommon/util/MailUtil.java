/**
 * @(#)MailUtil 1.0 10/13/2006
 *
 * Copyright (c) 2006
 */
package org.optimizationservices.oscommon.util;

import java.io.File;
import java.util.Vector;

import org.apache.commons.mail.EmailAttachment;
import org.apache.commons.mail.MultiPartEmail;

/**
 *
 * <P>The <code>MailUtil</code> class contains methods for performing
 * common basic EMail related operations </p>
 * </p>
 *
 * @author Jun Ma
 * @version 0.1, 10/13/2006
 *
 * @author Timothy Middelkoop
 * @version 0.2, 2010-04-15, move to Apache Commons Mail
 * @since 0.1
 */

public class MailUtil{

	/**
	 * m_sSMTPServer
	 */
	public String m_sSMTPServer = OSParameter.SMTP_SERVER;
	
	/**
	 * m_sFromEmail
	 */
	public String m_sFromEmail = OSParameter.FROM_EMAIL;
	
	/**
	 * m_sSMTPUser
	 */
	public String m_sSMTPUser = OSParameter.SMTP_USER;

	/**
	 * m_sSMTPPassword
	 */
	public String m_sSMTPPassword = OSParameter.SMTP_PASSWORD;

	/**
	 * m_sToEmail
	 */
	public String m_sToEmail = OSParameter.TO_EMAIL;

	/**
	 * m_sCCEmail
	 */
	public String m_sCCEmail = OSParameter.CC_EMAIL;

	/**
	 * m_sBCCEmail
	 */
	public String m_sBCCEmail = OSParameter.BCC_EMAIL;

	/**
	 * m_sSubject
	 */
	public String m_sSubject = OSParameter.MAIL_SUBJECT;

	/**
	 * m_sMessage
	 */
	public String m_sMessage = OSParameter.MAIL_MESSAGE;

	/**
	 * m_sAttachedFiles
	 */
	public String m_sAttachedFiles = OSParameter.MAIL_ATTACHED_FILES;
	
	/**
	 * Default constructor.
	 *
	 */
	public MailUtil(){
		
	}//constructor

	/**
	 * send an email
	 * @return whether the mail is sent successfully or not. 
	 */
	public boolean send(){
		return send(m_sFromEmail, m_sToEmail, m_sCCEmail, m_sBCCEmail, m_sSubject, m_sMessage, m_sAttachedFiles); 
	}//send
	
	/**
	 * send an email. 
	 * 
	 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
	 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses
	 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
	 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
	 * @param subject holds the email subject; uses default suject if null.
	 * @param message holds the email message body; uses default message if null.
	 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.
	 * @return whether the mail is sent successfully or not. 
	 */
	public boolean send(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
		m_sFromEmail = fromEmail;
		m_sToEmail = toEmail;
		m_sCCEmail = ccEmail;
		m_sBCCEmail = bccEmail;
		m_sSubject = subject;
		m_sMessage = message;
		m_sAttachedFiles = attachedFiles;

		// FIXME: This is probably broken when Java Mail was removed and converted to Apache commons mail.
		assert false; // UNTESTED!
		
		try{
			MultiPartEmail msg = new MultiPartEmail();
			msg.setHostName(m_sSMTPServer);
			msg.setSentDate(new java.util.Date());
			if(m_sFromEmail == null || m_sFromEmail.length() == 0){
				msg.setFrom(OSParameter.FROM_EMAIL);
			}
			else{
				msg.setFrom(m_sFromEmail);
			}
			if(m_sToEmail != null && m_sToEmail.length() > 0){
				Vector<String> vToEmails = CommonUtil.stringToVector(m_sToEmail, ",; \t\r\n");
				for(int i = 0; i < vToEmails.size(); i++){
					msg.addTo((String)vToEmails.elementAt(i).trim());					
				}
			}
			else{
				if(OSParameter.TO_EMAIL != null && OSParameter.TO_EMAIL.length()>0 )
					msg.addTo(OSParameter.TO_EMAIL);				
			}
			if(m_sCCEmail != null && m_sCCEmail.length() > 0){
				Vector<String> vCCEmails = CommonUtil.stringToVector(m_sCCEmail, ",; \t\r\n");
				for(int i = 0; i < vCCEmails.size(); i++){
					msg.addCc((String)vCCEmails.elementAt(i).trim());					
				}
			}
			if(m_sBCCEmail != null && m_sBCCEmail.length() > 0){
				Vector<String> vBCCEmails = CommonUtil.stringToVector(m_sBCCEmail, ",; \t\r\n");
				for(int i = 0; i < vBCCEmails.size(); i++){
					msg.addBcc((String)vBCCEmails.elementAt(i).trim());					
				}
			}
			msg.setSubject(m_sSubject==null?OSParameter.MAIL_SUBJECT:m_sSubject);
			if(m_sAttachedFiles == null){
				msg.setMsg(m_sMessage==null?OSParameter.MAIL_MESSAGE:m_sMessage);
			}
			else{
			    Vector<String> vAttachedFiles = CommonUtil.stringToVector(m_sAttachedFiles, ",; \t\r\n");
			    for(int i = 0; i < vAttachedFiles.size(); i++){
				    try {
				    	String sFileName = (String)vAttachedFiles.elementAt(i).trim();
				    	File file = new File(sFileName);
				    	if(!file.exists()){
				    		IOUtil.log("File [" + sFileName + "] doesn't exisit.", null);
				    		continue;
				    	}
						EmailAttachment attachment = new EmailAttachment();
						attachment.setPath(sFileName);
						msg.attach(attachment);
					} 
				    catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}
			    }
			}
			if(OSParameter.TO_EMAIL != null && OSParameter.TO_EMAIL.length()>0 )
				msg.send();
			return true;
		}
		catch (Exception e){
			e.printStackTrace();
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;		   
		}
	}//send
	
	/**
	 * send an email in a thread so that there is no wait time. 
	 * 
	 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
	 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses
	 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
	 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
	 * @param subject holds the email subject; uses default suject if null.
	 * @param message holds the email message body; uses default message if null.
	 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names. 
	 */
	public void sendInThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
		MailUtil mailUtil = new MailUtil();
		SendThread sendThread = mailUtil.new SendThread(fromEmail, toEmail, ccEmail, bccEmail, subject, message, attachedFiles);
		Thread thread = new Thread(sendThread);
		thread.start();
	}//sendInThread
	
	/**
	 * send an email in a thread so that there is no wait time. 
	 * 
	 */
	public void sendInThread(){
		MailUtil mailUtil = new MailUtil();
		SendThread sendThread = mailUtil.new SendThread(m_sFromEmail, m_sToEmail, m_sCCEmail, m_sBCCEmail, m_sSubject, m_sMessage, m_sAttachedFiles);
		Thread thread = new Thread(sendThread);
		thread.start();
	}//sendInThread
	
	/**
	 * <P>The <code>JAuthenticate</code> class is an internal authentication class used <code>MailUtil</code>.
	 */
	
	/**
	 * <P>The <code>SendThread</code> class is an internal thread controlled by <code>MailUtil</code>.
	 */
	protected class SendThread implements Runnable{
		/**
		 * m_sFromEmail holds the  from email address to send the email; uses default from email if null.  
		 */
		protected String m_sFromEmail = null;
		
		/**
		 * m_sToEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses.
		 */
		protected String m_sToEmail = null;
		
		/**
		 * m_sCCEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses.
		 */
		protected String m_sCCEmail = null;
		
		/**
		 * m_sBCCEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
		 */
		protected String m_sBCCEmail = null;
		
		/**
		 * m_sSubject holds the email subject; uses default suject if null.
		 */
		protected String m_sSubject = null;
		
		/**
		 * m_sMessage holds the email message body; uses default message if null.
		 */
		protected String m_sMessage = null;
		
		/**
		 * m_sAttachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.
		 */
		protected String m_sAttachedFiles = null;
		
		/**
		 * Constructor
		 * 
		 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
		 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses.
		 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
		 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
		 * @param subject holds the email subject; uses default suject if null.
		 * @param message holds the email message body; uses default message if null.
		 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names. 
		 */
		protected SendThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
			m_sFromEmail = fromEmail;
			m_sToEmail = toEmail;
			m_sCCEmail = ccEmail;
			m_sBCCEmail = bccEmail;
			m_sSubject = subject;
			m_sMessage = message;
			m_sAttachedFiles = attachedFiles;
		}//constructor
		
		/**
		 * A send method is implemented here. 
		 */
		public void run(){	
			MailUtil mailUtil = new MailUtil();
			mailUtil.send(m_sFromEmail, m_sToEmail, m_sCCEmail, m_sBCCEmail, m_sSubject, m_sMessage, m_sAttachedFiles);
		}//run		
	}//SendThread
	
	/**
	 * main for test purposes.
	 * 
	 * </p>
	 * 
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		MailUtil mailUtil = new MailUtil();
		System.out.println(mailUtil.send("maj@northwestern.edu", "junma1@gmail.com", null, null, "hii", "Hello World", null));
		//System.out.println(Parameter.SMTP_SERVER + "!!!!!!!!!!!!!!!!!");
		//System.out.println(mailUtil.send("ceport@cecco.com",  "maj@breaktech.com",  "", "", "hello", "Hello World", ""));
		//mailUtil.sendInThread("majxuh@hotmail.com",  null,  "", "", "Hi", "Hello World", null);
		//System.out.println(MailUtil.send("maj@northwestern.edu", "majxuh@hotmail.com", "maj@northwestern.edu", "maj@northwestern.edu", "hii", "Hello World", null));
		//System.out.println(mailUtil.send("maj@northwestern.edu",  null,  "", "xuhmaj@hotmail.com, majxuh@hotmail.com", "bccHii", "Hello World", Parameter.LOG_FILE+" "+"c:/s19o.qr"));
		//System.out.println(MailUtil.send(null, null,null, null, null));
		//System.out.println(MailUtil.send(null, null, "maj@iems.northwestern.edu", "maj@northwestern.edu", null, null, Parameter.LOG_FILE));
	}//main
	
}//class MailUtil
